// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_left(0x0B);
iarduino_I2C_Motor mot_right(0x0A);
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);


void setup() {

  delay(500);
  bum.begin();
  mot_left.begin();
  mot_right.begin();
  mot_left.setDirection(false);
  mot_right.setDirection(true);

  Serial.begin(9600);
}
int i = 0;
#define POROG_LINE 1500
#define KP 0.021
#define KI 0
#define KD 0
#define M0 80

void loop()
{
  int z = bum.getLineAnalog(3);
  int x = bum.getLineAnalog(7);
  //  Serial.println(q);
  //  Serial.println(p);
  int e = z - x;
  int p = e;
  int i = 0;// ...
  int d = 0;// ...
  int pid = p*KP+ i*KI+ d*KD;
  motor ( M0 +pid, M0 - pid );
}



void motor(int left_speed, int right_speed) {
  mot_left.setSpeed(left_speed, MOT_PWM);
  mot_right.setSpeed(right_speed, MOT_PWM);
}
