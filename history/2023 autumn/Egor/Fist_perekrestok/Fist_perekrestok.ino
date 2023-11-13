// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);
#define POROG_LINE 800

#define KP 0.022
#define KI 0.0015
#define KD 0.001
#define BASIC_SPEED 100
long int i = 0;
int e_old = 0;

bool flag = 1;
//bool flag = true;

int counter = 0;
void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);



}
void loop() {
  if (bum.getLineAnalog(3) > POROG_LINE || bum.getLineAnalog(7) > POROG_LINE) {
    if (flag == 0) {
      motor (100, 100);
      delay(300);
    }

    flag = 1;
    run_pid();
  }
  else {
    if (flag == 1) {
      flag = 0;
      counter ++; //counter = counter + 1;
      if (counter == 2) {

        motor (-100, -100);
        delay (100);
        motor (0, 0);
        delay (1000);
        while (1);
      }
    }

    motor (100, 100);
  }
}
void run_pid() {
  int l = bum.getLineAnalog(3);
  int r = bum.getLineAnalog(7);
  int e = l - r;
  int p = e;
  i = e + i * 0.95;
  int d = e - e_old;
  e_old = e;
  int pid = p * KP + i * KI + d * KD;
  motor(BASIC_SPEED + pid, BASIC_SPEED - pid);
}
void motor(int left_speed, int right_speed) {
  motor_left.setSpeed (left_speed, MOT_PWM);
  motor_right.setSpeed (right_speed, MOT_PWM);
}
