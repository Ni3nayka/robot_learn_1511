#include <SoftwareSerial.h>

#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  


SoftwareSerial bluetooth(11, 12);

#define TEST bluetooth

void setup() {
  delay(500);
  Serial.begin(9600);
  bluetooth.begin(9600);
  mot_R.begin();
  mot_L.begin();
  bum.begin();

  mot_R.setDirection(true);
  mot_L.setDirection(false);

  mot_R.setSpeed (0, MOT_PWM);
  mot_L.setSpeed (0, MOT_PWM);
}

int M = 100;

void loop() {
  if (TEST.available()) {
    char t = TEST.read();
    if (t=='F') motor(M, M);
    else if (t=='S') motor(0, 0);
    else if (t=='B') motor(-M, -M);
    else if (t=='L') motor(M, -M);
    else if (t=='R') motor(-M, M);
    else if (t=='0') M = 0;
    else if (t=='5') M = 25;
    else if (t=='q') M = 50;
  }
}

void motor(int a, int b) {
  mot_R.setSpeed (a, MOT_PWM);
  mot_L.setSpeed (b, MOT_PWM);
}
