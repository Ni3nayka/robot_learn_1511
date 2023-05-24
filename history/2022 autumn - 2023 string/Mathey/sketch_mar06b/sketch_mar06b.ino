#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);
void setup() {

  delay(500);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
Serial.begin (9600);
  
  
  

}

void loop() {
  if (Serial.available() > 0) {
    char f = Serial.read();
    //Serial.println (f);
    if (f == 'F') motor (100, 100);
    if (f == 'S') motor (0, 0);
    if (f == 'B') motor (-100, -100);
    if (f == 'R') motor (100, -100);
    if (f == 'L') motor (-100, 100);
  }
}

void motor(int l , int r) {
  mot_R.setSpeed(  r, MOT_PWM);
  mot_L.setSpeed(  l, MOT_PWM);



}
