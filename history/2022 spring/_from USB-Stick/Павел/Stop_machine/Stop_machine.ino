#include <Wire.h>

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

void setup() {
  
  delay(500); 
  Serial.begin(9600);
  mot_R.begin();
  mot_L.begin();
  bum.begin();

  mot_R.setDirection(true);
  mot_L.setDirection(false);

  forward();
  forward();
  forward();
  forward();
  right();
  forward();
  forward();
  motor(0, 0);
  delay(2000);
  left();
  forward();
  left();
  forward();
  forward();
  forward();
  motor(0, 0);
  delay(1000);
  left();
  left();
  forward();
  right();
  forward();
  forward();
  forward();
  forward();
  motor(50, 50);
  delay(500);
  motor(0, 0);
}

void forward(){
  while(bum.getLineAnalog(1)>1000 || bum.getLineAnalog(9)>1000) {
    PID();
  }
  motor(50, 50);
  delay(850);
  motor(0, 0);
}

void left(){
  while(bum.getLineAnalog(1)>1000){
    motor(50, -50);
  }
  motor(50, -50);
  delay(100);
}

void right(){
  while(bum.getLineAnalog(9)>1000){
    motor(-50, 50);
  }
  motor(-50, 50);
  delay(100);
}

void loop() {
  
}

void PID(){ 
  
  int e=0;
  if (bum.getLineAnalog(1)<1000) e-=32;
  if (bum.getLineAnalog(2)<1000) e-=16;
  if (bum.getLineAnalog(3)<1000) e-=8;
  if (bum.getLineAnalog(4)<1000) e-=4;
  if (bum.getLineAnalog(6)<1000) e+=4;
  if (bum.getLineAnalog(7)<1000) e+=8;
  if (bum.getLineAnalog(8)<1000) e+=16;
  if (bum.getLineAnalog(9)<1000) e+=32;
  
  mot_R.setSpeed(50-e, MOT_PWM);
  mot_L.setSpeed(50+e, MOT_PWM);
}

void motor(int a, int b) {
  mot_R.setSpeed (a, MOT_PWM);
  mot_L.setSpeed (b, MOT_PWM);
}
