#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);

void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);
  forward();
  forward();
  turn_left();
  forward();
  forward();
  turn_right();
  forward();
  forward();
  forward();
  turn_right();
  forward();
  forward();
  forward();
  forward();
  turn_right();
  forward();
  forward();
  forward();
  turn_right();
  forward();
  forward();
  turn_left();
  forward();
  motor(100,100);
  delay(200);
  motor(0,0);
}

void loop() {
  // int A = bum.getLineAnalog(3); // белое - 2700  черное - 330
  //  int B = bum.getLineAnalog(7);
  // int e = A - B;
  // int P = e*0.05;
  // int left = 100 + P;
  //  int right = 100 - P;
  //  motor (left, right);
  // p_regulator();

}
int LINE_POROG = 1500;

void turn_left() {
  motor(-100,100);
  while (bum.getLineAnalog(3)<LINE_POROG);
  while (bum.getLineAnalog(3)>LINE_POROG);
  while (bum.getLineAnalog(3)<LINE_POROG);
  motor(100,-100);
  delay(50);
  motor(0,0);
}

void turn_right() {
  motor(100,-100);
  while (bum.getLineAnalog(7)<LINE_POROG);
  while (bum.getLineAnalog(7)>LINE_POROG);
  while (bum.getLineAnalog(7)<LINE_POROG);
  motor(-100,100);
  delay(50);
  motor(0,0);
}


void forward () {
  while (bum.getLineAnalog(0) > 1500 && bum.getLineAnalog(9) > 1500) {
    p_regulator();

  }
  // motor(100, 100);
  //delay (480);
  unsigned long int t = millis() + 450;
  while (t > millis()) {
    p_regulator();
  }
  motor(0, 0);
}

void p_regulator () {
  int A = bum.getLineAnalog(3); // белое - 2700  черное - 330
  int B = bum.getLineAnalog(7);
  int e = A - B;
  int P = e * 0.05;
  int left = 100 + P;
  int right = 100 - P;
  motor (left, right);
}
void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}
