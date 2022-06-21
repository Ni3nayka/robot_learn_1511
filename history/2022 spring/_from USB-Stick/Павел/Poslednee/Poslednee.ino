#include <SoftwareSerial.h>
#include <Wire.h>

#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

SoftwareSerial bluetooth(11, 12);

#define TEST bluetooth

int X = -1;
int Y = -1;

void setup() {
  delay(500);
  Serial.begin(9600);
  bluetooth.begin(9600);
  mot_R.begin();
  mot_L.begin();
  bum.begin();

  mot_R.setDirection(true);
  mot_L.setDirection(false);
}

void loop() {
  if (TEST.available()) {
    char t = TEST.read();
    if      (t=='A') X=1;
    else if (t=='B') X=2;
    else if (t=='C') X=3;
    else if (t=='D') X=4;
    
    else if (t=='1') Y=1;
    else if (t=='2') Y=2;
    else if (t=='3') Y=3;
    else if (t=='4') Y=4;
    else if (t=='5') Y=5;

    if (X!=-1 && Y!=-1){
      forward();
      forward();
      for (int i=1; i<X; i++) forward();
      if (Y<3) left();
      else if (Y>3) right();
      if (Y!=3) {
        for (int i=0; i<abs(Y-3); i++) forward();
        motor(0, 0);
        delay(1000);
        IOOO();
        vozvrat();
      }
      else if (Y==3){
        motor(0, 0);
        delay(1000);
        IOOO();
        vozvrat();
      }
    }
  }
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
  delay(150);
}

void IOOO(){
  left();
  left();
}

void right(){
  while(bum.getLineAnalog(9)>1000){
    motor(-50, 50);
  }
  motor(-50, 50);
  delay(100);
}

void vozvrat(){
  for (int i=0; i<abs(Y-3); i++) forward();
        if(Y>3) left();
        else if(Y<3) right();
        for (int i=0; i<X; i++) forward();
        motor(50, 50);
        delay(650);
        motor(0, 0);
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
