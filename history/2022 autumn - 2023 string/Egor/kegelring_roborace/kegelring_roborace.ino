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
  //ataka();
}

//  while (bum.getLineAnalog(1) > 1500 && bum.getLineAnalog(9) > 1500) {

void ataka() {
  while (bum.getLineAnalog(5)>2300) {
    motor(100,100);
  }
  motor(-100,-100);
  delay(2000);
  motor(0,0);
}

void loop() {
  //Serial.println(bum.getLineAnalog(5));  
  distanse();
  if (cm<30) { 
    ataka(); 
    time = millis(); 
  }
  else if (millis()-time<2000) {
    // вращаемся
  }
  else {
    motor(0,0);
  }
}

void distanse() {
  digitalWrite(PIN_TRIG, 0);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, 0);
  int duration = pulseIn(PIN_ECHO, 1);
  cm = (duration / 2) / 29.1;
  delay(100);
}

void motor(int L, int R) {
  mot_L.setSpeed(L, MOT_PWM);
  mot_R.setSpeed(R, MOT_PWM);
}
