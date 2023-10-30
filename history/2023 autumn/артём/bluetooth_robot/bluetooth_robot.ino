// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_left(0x0B);
iarduino_I2C_Motor mot_right(0x0A);

#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 12); // RX, TX

void setup() {

  delay(500);

  mot_left.begin();
  mot_right.begin();
  mot_left.setDirection(true);
  mot_right.setDirection(false);

  mySerial.begin(9600);
}
int i = 0;

void loop() {

  //  Serial.println(a);//
  //Serial.println("123\n123");//
  if (mySerial.available() > 0) {
    char symbol = mySerial.read();

    if (symbol == 'S')
      motor(0, 0);

    if (symbol == 'F')
      motor(100, 100);

    if (symbol == 'L')
      motor(100, 0);
    if (symbol == 'R')
      motor(0, 100);
    if (symbol == 'B')
      motor(-100, -100);
    if (symbol == 'G')
      motor(100, 50);
    if (symbol == 'I')
      motor(50, 100);
    if (symbol == 'H')
      motor(-100, -50);
    if (symbol == 'J')
      motor(-50, -100);
  }
}

void motor(int left_speed, int right_speed) {
  mot_left.setSpeed(left_speed, MOT_PWM);
  mot_right.setSpeed(right_speed, MOT_PWM);
}
