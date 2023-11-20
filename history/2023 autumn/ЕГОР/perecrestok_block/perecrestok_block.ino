#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);

#define Kp 0.05
#define M0 100
#define LINE_POROG 1500

void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);

  for (int i = 0; i<3; i++) {
    forward();
  }
  
  int i = 0;
  while (i<3) {
    forward();
    i++;
  }
  
  forward();
  forward();
  forward();
}

void loop() { 
  //p_regulator();
}

void turn_left() {
  motor(-100,100);
  while (bum.getLineAnalog(3)<LINE_POROG);
  while (bum.getLineAnalog(3)>LINE_POROG);
  while (bum.getLineAnalog(3)<LINE_POROG);
  motor(100,-100);
  delay(50);
  motor(0,0);
}

void forward() {
  while(bum.getLineAnalog(1)>LINE_POROG && bum.getLineAnalog(9)>LINE_POROG){
    p_regulator();
  }
  unsigned long int t = millis()+450;
  while(t>millis() ){
    p_regulator();
  }
  motor(0,0);
}

void p_regulator() {
  int e = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  int p = e*Kp;
  motor(M0 + p, M0 - p);
}

void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}
