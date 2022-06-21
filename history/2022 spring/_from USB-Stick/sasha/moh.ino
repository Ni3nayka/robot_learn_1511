#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11, 12); // RX, TX               
#define TEST bluetooth

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0B);     
iarduino_I2C_Motor mot_L(0x0A);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

int X = -1;
int Y = -1;

unsigned long int t = 0;

void setup(){       
    delay(500); 
    Serial.begin(9600);
    bluetooth.begin(9600);
    //Определяем вводы и выводы
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false);
    
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);
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
  if (bum.getLineAnalog(1)<1000 && bum.getLineAnalog(9)<1000) return 0;
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

void loop()
{ 
  if(TEST.available())
  {
    char t = TEST.read();

    if (t=='A') X = 1;
    else if (t=='B') X = 2;
    else if (t=='C') X = 3;
    else if (t=='D') X = 4;

    else if (t=='1') Y = 1;
    else if (t=='2') Y = 2;
    else if (t=='3') Y = 3;
    else if (t=='4') Y = 4;
    else if (t=='5') Y = 5;
  }

  if (X!=-1 && Y!=-1)
  {
    Serial.print("X: ");
    Serial.print(X);
    Serial.print("Y: ");
    Serial.print(Y);
    Serial.println();
    forward();
    forward();
    for (int i = 1; i<X; i++) forward();
    if (Y>3) right();
    else if (Y<3) left();
    if (Y!=3)
    {
      for(int i = 0; i<abs(Y-3); i++) forward();
    }
    delay(1000);
    right();
    right();
    if (Y!=3)
    {
      for(int i = 0; i<abs(Y-3); i++) forward();
    }
    if (Y<3) right();
    else if (Y>3) left();
    for (int i = 1; i<X; i++) forward();
    forward();
    mot_R.setSpeed(100, MOT_PWM);
    mot_L.setSpeed(100, MOT_PWM);
    delay (500);
    mot_R.setSpeed(0, MOT_PWM);
    mot_L.setSpeed(0, MOT_PWM);
    while (1);
  }
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
