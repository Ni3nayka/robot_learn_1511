#include <SoftwareSerial.h>

#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  
#define PIN_TRIG 12
#define PIN_ECHO 11

long duration, cm;

void setup() {
  delay(500);
  Serial.begin(9600);
  mot_R.begin();
  mot_L.begin();
  bum.begin();

  mot_R.setDirection(true);
  mot_L.setDirection(false);

  mot_R.setSpeed (0, MOT_PWM);
  mot_L.setSpeed (0, MOT_PWM);

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void linia() {
  int e=0;
  if (bum.getLineAnalog(1)<1000) e-=32;
  if (bum.getLineAnalog(2)<1000) e-=16;
  if (bum.getLineAnalog(3)<1000) e-=8;
  if (bum.getLineAnalog(4)<1000) e-=4;
  if (bum.getLineAnalog(6)<1000) e+=4;
  if (bum.getLineAnalog(7)<1000) e+=8;
  if (bum.getLineAnalog(8)<1000) e+=16;
  if (bum.getLineAnalog(9)<1000) e+=32;
  
  mot_R.setSpeed(75-e, MOT_PWM);
  mot_L.setSpeed(75+e, MOT_PWM);
}

bool coord() {
  for (int i=1; i<=9; i++) {
    if (bum.getLineAnalog(i)<1000){
      return 0;
    }
  }
  return 1;
}

int nagibator(){
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);

  cm = (duration / 2) / 29.1;
  delay(250);

  return cm;
}
void loop(){
  /*int y = nagibator();
  if (bum.getLineAnalog(4)>1000, bum.getLineAnalog(6)>1000) {
    if (y>20){
      motor(-50, 50);
    }
    else {
      motor(50, 50);
    }
  }
  else {
    motor(-50, -50);
    delay(500);
  }*/
  if (nagibator()>25) {
    motor(-25, 25);
  }
  else {
   while (coord()) {
     motor(75, 75);
   }
   motor(-50, -50);
   delay(2400);
  }
}

void motor(int a, int b) {
  mot_R.setSpeed (a, MOT_PWM);
  mot_L.setSpeed (b, MOT_PWM);
}
