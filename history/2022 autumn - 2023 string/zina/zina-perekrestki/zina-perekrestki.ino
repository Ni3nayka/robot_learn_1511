#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0A);
iarduino_I2C_Motor mot_R(0x0B);
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#define PIN_TRIG 4
#define PIN_ECHO 5
long duration, cm;
int M = 100;

void setup() {
  delay(500);
  mot_L.begin();
  mot_R.begin();
  mot_R.setDirection(true);
  mot_L.setDirection(false);
  Serial.begin(9600);
  bum.begin();
  forward();
  forward();
  left();
  forward();
  right();
 forward();
  forward();
  left();
  forward();
  right();
  forward();
  delay(5005);
  right();
  right();
  forward();
  left();
  forward();
  right();
  forward();
  forward();
  left();
  forward();
  right();
  forward();
  motor(100, 100);
  delay (150);
  motor(0, 0);

}
void loop() {}

void motor(int l, int r) {
  mot_L.setSpeed( l, MOT_PWM);
  mot_R.setSpeed( r, MOT_PWM);
}
void forward() {
  while (bum.getLineAnalog (1) > 1500 && bum.getLineAnalog (9) > 1500 ) {

    int P = (bum.getLineAnalog (8) - bum.getLineAnalog (2)) ;
    int z = P * 0.04;
    motor (M - z, M + z);
  } motor (100, 100);
  delay (100);
  unsigned long int time = millis();
  while (time + 335 > millis ()) {
    int P = (bum.getLineAnalog (8) - bum.getLineAnalog (2)) ;
    int z = P * 0.04;
    motor (M - z, M + z);

  }
  motor (0, 0);
}
void right () {
 motor (100,-100);
 delay(300);
 while (bum.getLineAnalog (8) < 1500) {
    motor (100, -100);

  }
  while (bum.getLineAnalog (8) > 1500) {
    motor (100, -100);
  }
  while (bum.getLineAnalog (8) < 1500) {
    motor (100, -100);

  } motor(0, 0);
}

void left () {
  while (bum.getLineAnalog (2) < 1500) {
    motor (-100, 100);

  }
  while (bum.getLineAnalog (2) > 1500) {
    motor (-100, 100);
  }
  while (bum.getLineAnalog (2) < 1500) {
    motor (-100, 100);

  } motor(0, 0);
}
