#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);


int cm = 0;
const int PIN_TRIG = 12;
const int PIN_ECHO = 11;

unsigned long int time = 0;

void setup() {
  delay(500);
  Serial.begin(9600);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
  mot_R.setDirection(true);
  bum.begin();
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  motor(0,0);
  
  //forward();
  //right();
  
  forward();
  left();
  ananas();
  if (cm<15) {
    forward();
    stop();
  }
  else if (cm<40) {
    forward();
    forward();
    stop();
  }
  right();
  
  right();
  ananas();
  if (cm<15) {
    forward();
    stop();
  }
  else if (cm<40) {
    forward();
    forward();
    stop();
  }
  left();
}

void stop() {
  while(1);
}

void loop() {
//  ananas();
//  Serial.println(cm);
}

void left() {
  motor(-50,50);
  while (bum.getLineAnalog(1)<1500);
  while (bum.getLineAnalog(1)>1500);
  while (bum.getLineAnalog(1)<1500);
  delay(50);
  motor(0,0);
  test();
}

void test() {
  ananas();
  if  (cm<15) {
    while(1);
  }
}

void right() {
  motor(50,-50);
  OBJECT = 0;
  while (bum.getLineAnalog(9)<1500) {
    ananas();
    if (cm<15) { OBJECT = 1; }
  }
  while (bum.getLineAnalog(9)>1500);
  while (bum.getLineAnalog(9)<1500);
  delay(50);
  motor(0,0);
  test()
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
  test()
}

void motor(int L, int R) {
  mot_L.setSpeed(L, MOT_PWM);
  mot_R.setSpeed(R, MOT_PWM);
}
