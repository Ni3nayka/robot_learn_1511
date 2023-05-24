#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot(0x0A);
iarduino_I2C_Motor motor(0x0B);

int cm = 0;
const int trig = 12;
const int echo = 11;


const int beliy = 1500;
const int skorost = 80;
void setup() {
  Serial.begin(9600);
  delay(500);
  motor.begin();
  mot.begin();
  mot.setDirection(true);
  motor.setDirection(false);
  delay(500);
  Serial.begin(9600);
  bum.begin();

}
long int I = 0;
void loop() {
  Serial.println(bum.getLineAnalog(5));
 
  zona(); 
  //Serial.println(cm)
  
}
  //int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);





void ben(int l, int r) {
  mot.setSpeed(r, MOT_PWM);

  motor.setSpeed(l, MOT_PWM);


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


void ataka() {
  while(bum.getLineAnalog(5)>2300) {
    ben(100,100);
    
  }
  ben(-100,-100);
  delay(2000);
  ben(0,0);
}
