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
const int POROG_LINE = 1500;
void loop()
{
  int q = bum.getLineAnalog(3);
  int p = bum.getLineAnalog(7);
  //  Serial.println(q);
  //  Serial.println(p);
  if ( q > POROG_LINE and p > POROG_LINE)
    motor(100, 100);
  if ( q < POROG_LINE and p >POROG_LINE )
    motor (0 , 50);
  if ( q > POROG_LINE and p < POROG_LINE )
    motor (50 , 0);
  if ( q < POROG_LINE and p < POROG_LINE )
    motor( 100, 100);
}



void motor(int left_speed, int right_speed) {
  mot_left.setSpeed(left_speed, MOT_PWM);
  mot_right.setSpeed(right_speed, MOT_PWM);
}
