#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);

int cm = 0;

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

unsigned long int time = 0;

void setup() {

  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN , INPUT);





  delay(500);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
  Serial.begin (9600);
  bum.begin();
time=millis();
  //secondgear();

}
long int I = 0;
void loop() {
  Ananas();
  Serial.println(cm);
  if (cm < 25)
  {
    secondgear();
    time=millis();
  }
  else if (millis()-time<2000){
    motor(30, -30);
    
  }
else {
  motor(0,0);
}







}

void motor(int l , int r) {
  mot_R.setSpeed(  r, MOT_PWM);
  mot_L.setSpeed(  l, MOT_PWM);
}
void secondgear() {
  motor(30, -30);
  delay(200);
  while (bum.getLineAnalog(5) > 2250) {
    motor (100, 100);

  }
  motor(-100, -100);
  delay(1000);
  motor(0, 0);
}

void Ananas () {
  digitalWrite (TRIGGER_PIN, 0);
  delayMicroseconds (5);
  digitalWrite(TRIGGER_PIN, 1);
  delayMicroseconds(10);
  digitalWrite (TRIGGER_PIN, 0);
  int duration = pulseIn(ECHO_PIN, 1);
  cm = (duration / 2) / 29.1;
  delay (100);


}
