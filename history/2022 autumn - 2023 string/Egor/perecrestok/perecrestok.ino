#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

void setup() {
  delay(500);
  Serial.begin(9600);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
  mot_R.setDirection(true);
  bum.begin();
  motor(0,0);

  //vpered();
  right();
}

void vpered() {
  // до перекрестка
  while (bum.getLineAnalog(1) > 1500 && bum.getLineAnalog(9) > 1500) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e*0.03; 
    motor(50+P,50-P);
  }
  // проезжаем перекресток
  motor(50,50);
  delay(200);
  // едем до середины перекрестка
  unsigned long int time = millis();
  while (time+650>millis()) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e*0.03; 
    motor(50+P,50-P);
  }
  // останавливаемся
  motor(0,0);
}

void left() {
  motor(-50,50);
  while (bum.getLineAnalog(2)<1500);
  while (bum.getLineAnalog(2)>1500);
  while (bum.getLineAnalog(2)<1500);
  motor(0,0);
}

void right() {
  motor(50,-50);
  while (bum.getLineAnalog(8)<1500);
  while (bum.getLineAnalog(8)>1500);
  while (bum.getLineAnalog(8)<1500);
  motor(0,0);
}

void loop() {}

void motor(int L, int R) {
  mot_L.setSpeed(L, MOT_PWM);
  mot_R.setSpeed(R, MOT_PWM);
}
