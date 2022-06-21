
#include <Wire.h>
#include <iarduino_I2C_Motor.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Motor mot_R(0x0B);
iarduino_I2C_Motor mot_L(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

long int d = 0;
int e_old = 0;

void setup() {
  delay(500);
  Serial.begin(9600);
  mot_R.begin();
  mot_L.begin();
  bum.begin();

  mot_R.setDirection(false);
  mot_L.setDirection(true);

  mot_R.setSpeed(  50.0, MOT_PWM);

  unsigned long int t = millis();
  while(millis()<10000) forward();
  ostanovka();
  delay(1000);
  mot_R.setSpeed(-50, MOT_PWM);
  mot_L.setSpeed( 50, MOT_PWM);
  delay(1500);
  ostanovka();
  delay(1000);
  t = millis();
  while(millis()-t<10000) forward();
  ostanovka();

 


}


void forward() {
  if (bum.getLineAnalog(1)<1000 && bum.getLineAnalog(9)>1000) {
    motor(-40);           
  }
  else if (bum.getLineAnalog(1)>1000 && bum.getLineAnalog(9)<1000) {
    motor(40);
  }
  else {
    motor(0);
  }
 }

int test_datchik() {

  int e = 0;
  if (bum.getLineAnalog(1) < 1000) e -= 32;
  if (bum.getLineAnalog(2) < 1000) e -= 16;
  if (bum.getLineAnalog(3) < 1000) e -= 8;
  if (bum.getLineAnalog(4) < 1000) e -= 4;
  if (bum.getLineAnalog(6) < 1000) e += 4;
  if (bum.getLineAnalog(7) < 1000) e += 8;
  if (bum.getLineAnalog(8) < 1000) e += 16;
  if (bum.getLineAnalog(9) < 1000) e += 32;
  return -e;
}
int operating_pid(int e) {
  int p = e;
  d = d - (e_old - e) / 25;
  e_old = e;
  int pid =  (p + d) / 2;
  return pid;
}

void loop() {
  unsigned long int t = millis();
  if (t>3000) {
    Serial.println("!");
  }
  int e = test_datchik();
  int pid = operating_pid(e);
  motor(pid);
}


void motor(int a) {
  mot_R.setSpeed(70 - a, MOT_PWM);
  mot_L.setSpeed(70 + a, MOT_PWM);

}

void ostanovka() {
  mot_R.setSpeed(0, MOT_PWM);
  mot_L.setSpeed(0, MOT_PWM);

}
