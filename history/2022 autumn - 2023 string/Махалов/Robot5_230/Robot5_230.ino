#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot(0x0A);
iarduino_I2C_Motor motor(0x0B);
#include <NewPing.h>

#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 500 
NewPing sonar(TRIGGER_PIN,ECHO_PIN, MAX_DISTANCE);
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
  
  int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  int p= err;
  I= I*0.9 +p;
  int hlebushek = p*0.033 + I*0.0000000000001;
  ben(100+hlebushek, 100-hlebushek);
}




void ben(int l, int r) {
  mot.setSpeed(r, MOT_PWM);

  motor.setSpeed(l, MOT_PWM);


}
