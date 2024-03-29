#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);

#define POROG_LINE 1500

#define KP 0.02
#define KI 0.0015
#define KD 0.0001
#define BASIC_SPEED 100

long int i = 0;
int e_old = 0;

void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);
}

void loop() { // белое - 2700  черное - 330
  int l = bum.getLineAnalog(3);
  int r = bum.getLineAnalog(7);
  int e = l - r;
  int p = e;
  i = e + i*0.95;
  int d = e - e_old;
  e_old = e;
  int pid = p*KP + i*KI + d*KD;
  motor(BASIC_SPEED+pid,BASIC_SPEED-pid);
}

void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}
