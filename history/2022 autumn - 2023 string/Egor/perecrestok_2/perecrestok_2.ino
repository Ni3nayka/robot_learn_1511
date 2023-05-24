#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

unsigned long int time = 0;

void setup() {
  delay(500);
  Serial.begin(9600);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
  mot_R.setDirection(true);
  bum.begin();
  motor(0,0);
  
  //forward();
  right();
  
}

void loop() {
  // bum.getLineAnalog(1) > 1500 - белое
//  int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
//  int P = e*0.03; 
//  motor(50+P,50-P);
}

void left() {
  motor(-50,50);
  while (bum.getLineAnalog(1)<1500);
  while (bum.getLineAnalog(1)>1500);
  while (bum.getLineAnalog(1)<1500);
  delay(50);
  motor(0,0);
}

void right() {
  motor(50,-50);
  while (bum.getLineAnalog(9)<1500);
  while (bum.getLineAnalog(9)>1500);
  while (bum.getLineAnalog(9)<1500);
  delay(50);
  motor(0,0);
}

void forward() {
  while (bum.getLineAnalog(1)>1500 && bum.getLineAnalog(9)>1500) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e*0.03; 
    motor(50+P,50-P);
  }
  time = millis();
  while (time+900>millis()) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e*0.03; 
    motor(50+P,50-P);
  }
  motor(0,0);
}

void motor(int L, int R) {
  mot_L.setSpeed(L, MOT_PWM);
  mot_R.setSpeed(R, MOT_PWM);
}
