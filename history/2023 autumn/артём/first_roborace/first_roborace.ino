// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_left(0x0B);
iarduino_I2C_Motor mot_right(0x0A);

void setup() {
  delay(500);
  mot_left.begin();
  mot_right.begin();
  mot_left.setDirection(true);
  mot_right.setDirection(false);
  mot_left.setSpeed(-100, MOT_PWM);
  mot_right.setSpeed(-100, MOT_PWM);

}
int i = 0;

void loop() {
while(i<=3){
  i++;
motor(100,100);
delay(1000);
motor(50,0);
delay(1500);
}
delay(1);
motor(0,0);

}

void motor(int left_speed, int right_speed) {
  mot_left.setSpeed(left_speed, MOT_PWM);
  mot_right.setSpeed(right_speed, MOT_PWM);
}
