#include <Wire.h>               

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  




void setup(){       
    delay(500); 
    Serial.begin(9600);
    //Определяем вводы и выводы
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false);
    
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);


    delay(1000);
    
   forward();
   forward();
   forward();
   forward();
   right();
   forward();
   forward();
   delay(2000);
}

void forward() {
  while (test_no_end()) {
    dvigenie();
  }
  motor(70,70);
  delay(800);
  motor(0,0);
}

void left() {
  motor(70,-70);
  while(bum.getLineAnalog(1)<1000); delay(50);
  while(bum.getLineAnalog(1)>1000); delay(50);
  while(bum.getLineAnalog(1)<1000); delay(50);
  motor(0,0);
}

void right() {
  motor(-70,70);
  while(bum.getLineAnalog(9)<1000); delay(50);
  while(bum.getLineAnalog(9)>1000); delay(50);
  while(bum.getLineAnalog(9)<1000); delay(50);
  motor(0,0);
}

bool test_no_end() {
  if (bum.getLineAnalog(1)<1000 || bum.getLineAnalog(9)<1000) return 0;
  else return 1;
}

void dvigenie(){ 
  int e = 0;
  if (bum.getLineAnalog(1)<1000) e -= 32;
  if (bum.getLineAnalog(2)<1000) e -= 16;
  if (bum.getLineAnalog(3)<1000) e -= 8;
  if (bum.getLineAnalog(4)<1000) e -= 4;
  //if (bum.getLineAnalog(0)<1000) e -= 0;
  if (bum.getLineAnalog(6)<1000) e += 4;
  if (bum.getLineAnalog(7)<1000) e += 8;
  if (bum.getLineAnalog(8)<1000) e += 16;
  if (bum.getLineAnalog(9)<1000) e += 32;
  
  mot_R.setSpeed(70-e, MOT_PWM);
  mot_L.setSpeed(70+e, MOT_PWM);
}

void loop(){ 
  /*if (millis()-t>8000) {
    motor(0,0);
    while (1) 
      delay(1000);
  }
  if (test_distance()>25) {
    motor(-20,20);
  }
  else {
    motor(100,100);
    while (test_coordinata()) {
      delay(10);
    }
    motor(0,0);
    delay(100);
    motor(-100,-100);
    delay(1000);
    t = millis();
  }*/
}


void motor(int a, int b) {
  mot_R.setSpeed(a, MOT_PWM);
  mot_L.setSpeed(b, MOT_PWM);
}
