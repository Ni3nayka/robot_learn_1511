#include <Wire.h>
#include <iarduino_I2C_Motor.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Motor mot_a(0x0A);
iarduino_I2C_Motor mot_b(0x0B);
iarduino_I2C_Bumper bum(0x0C);
const int IN1=1,IN2=2,IN3=3,IN4=4,IN5=5,IN6=6,IN7=7,IN8=8,IN9=9;
int irAnalog(int n){return bum.getLineAnalog(n);}
bool irWhite(int n,int p){return irAnalog(n)>p;}
bool irBlack(int n,int p){return irAnalog(n)<p;}
void startMotor(int n,int s){if(n==1)mot_a.setSpeed(s,MOT_PWM);else if(n==2)mot_b.setSpeed(s,MOT_PWM);}
void stopMotor(int n){startMotor(n,0);}
void stopMotorHard(int n){startMotor(n,0);}

void setup() {
delay(500);
mot_a.begin();
mot_b.begin();
mot_a.setDirection(false);
mot_b.setDirection(true);
bum.begin();
  
  Serial.begin(9600);
  motor(0,0);
}

void loop() {
  // bum.getLineAnalog(1) > 1500 - белое
  int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
  int P = e*0.03; 
  motor(50+P,50-P);
}



void motor(int L, int R) {
  mot_a.setSpeed(L, MOT_PWM);
  mot_b.setSpeed(R, MOT_PWM);
}
