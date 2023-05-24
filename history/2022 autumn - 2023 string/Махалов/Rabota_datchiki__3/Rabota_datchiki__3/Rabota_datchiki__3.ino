#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor ml(0x0A);
iarduino_I2C_Motor mr(0x0B);
unsigned long int time = 0;

const int beliy = 1500;
const int skorost = 80;
void setup() {
  Serial.begin(9600);
  delay(500);
  ml.begin();
  mr.begin();
  ml.setDirection(true);
  mr.setDirection(false);
  bum.begin();
  forward();
  forward();
  left();
  forward();
  forward();
  right();
  forward();
  forward();
  forward();
  right();
  forward();
  forward();
  right();
  forward();
  left();
  left();
  delay(3000);
  forward();
  right();
  forward();
  forward();
  right();
  forward();
  forward();
  right();
  forward();
  left();
  forward();
  right();
  forward();
  left();
  forward();
  delay(500);
  ben(50,50);
  delay(550);
  ben(0,0);
}
void loop() {
  
  //Serial.println(bum.getLineAnalog(5));
 
  //zona(); 
  //Serial.println(cm)
  
}
  //int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);





void ben(int l, int r) {
  mr.setSpeed(r, MOT_PWM);

  ml.setSpeed(l, MOT_PWM);


}



void forward() {
  while(bum.getLineAnalog(1)>1500 && bum.getLineAnalog(9)>1500) {
    int e = (bum.getLineAnalog(7) - bum.getLineAnalog(3));
    int p = e*0.046;
    ben(100+p,100-p);
  }
  time=millis();
  while(time+420>millis()) {
    int e = (bum.getLineAnalog(7) - bum.getLineAnalog(3));
    int p = e*0.046;
    ben(100+p,100-p);
  }
  ben(0,0);
}
void left() {
  ben(100,-100);
   while(bum.getLineAnalog(1)<1500);
   while(bum.getLineAnalog(1)>1500);
   while(bum.getLineAnalog(1)<1500);
   //delay(50);
   ben(0,0);
}
void right() {
  ben(-100,100);
   while(bum.getLineAnalog(9)<1500);
   while(bum.getLineAnalog(9)>1500);
   while(bum.getLineAnalog(9)<1500);
   //delay(50);
   ben(0,0);
}
