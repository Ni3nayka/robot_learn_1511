#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor ml(0x0A);
iarduino_I2C_Motor mr(0x0B);
unsigned long int time = 0;
int cm = 0;
const int trig = 12;
const int echo = 11;
const int beliy = 1500;
const int skorost = 80;
void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
  delay(500);
  ml.begin();
  mr.begin();
  ml.setDirection(true);
  mr.setDirection(false);
  bum.begin();
  f1();
  f1();
  l();
  f1();
  f1();
  r();
  f1();
  r();
  f1();
  f1();
  f1();
  f1();
  l();
  f1();
  l();
  f1();
  f1();
  f1();
  f1();
  r();
  f1();
  r();
  f1();
  f1();
  f1();
  f1();
  r();
  f1();
  f1();
  f1();
  r();
  f1();
  f1();
  
}
void loop() {
  
  //Serial.println(bum.getLineAnalog(5));
 
  zona(); 
  Serial.println(cm);
  
}
  //int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);





void ben(int l, int r) {
  mr.setSpeed(r, MOT_PWM);

  ml.setSpeed(l, MOT_PWM);


}
void f1() {
  f();
  test();
}



void f() {
  while(bum.getLineAnalog(1)>1500 && bum.getLineAnalog(9)>1500) {
    int e = (bum.getLineAnalog(7) - bum.getLineAnalog(3));
    int p = e*0.035;
    ben(100+p,100-p);
  }
  time=millis();
  while(time+420>millis()) {
    int e = (bum.getLineAnalog(7) - bum.getLineAnalog(3));
    int p = e*0.035;
    ben(100+p,100-p);
  }
  ben(0,0);
}
void l() {
  ben(100,-100);
   while(bum.getLineAnalog(1)<1500);
   while(bum.getLineAnalog(1)>1500);
   while(bum.getLineAnalog(1)<1500);
   //delay(50);
   ben(0,0);
   test();
}
void r() {
  ben(-100,100);
   while(bum.getLineAnalog(9)<1500);
   while(bum.getLineAnalog(9)>1500);
   while(bum.getLineAnalog(9)<1500);
   //delay(50);
   ben(0,0);
   test();
}

void test() {
 zona();
  if (cm<15) {
    f();
    while(1);
    
}
}

void zona() {
  digitalWrite(trig, 0);
  delayMicroseconds(5);
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);
  int load = pulseIn(echo, 1);
  cm = (load / 2) / 29.1;
  delay(100);
}
