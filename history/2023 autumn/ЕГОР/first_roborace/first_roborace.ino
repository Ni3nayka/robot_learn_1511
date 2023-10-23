#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);

  motor(100,100);
  delay(1000);
  motor(100,-100);
  delay(450);

  motor(100,100);
  delay(1000);
  motor(100,-100);
  delay(450);

  motor(100,100);
  delay(1000);
  motor(100,-100);
  delay(450);

  motor(100,100);
  delay(1000);
  motor(100,-100);
  delay(450);
}

void loop() {}

void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}
