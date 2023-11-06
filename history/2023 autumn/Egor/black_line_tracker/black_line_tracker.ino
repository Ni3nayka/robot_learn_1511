// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>                           //   Подключаем библиотеку для работы с бампером I2C-flash.
iarduino_I2C_Bumper bum(0x0D);
const int POROG_LINE = 800;


void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);



}
void loop() {
  int l = bum.getLineAnalog(3);
  int r = bum.getLineAnalog(7);
  //Serial.println(l);
  if (l > POROG_LINE && r > POROG_LINE) motor (100, 100);
  if (l < POROG_LINE && r > POROG_LINE) motor (20, 100);
  if (l > POROG_LINE && r < POROG_LINE) motor (100, 20);
  if (l < POROG_LINE && r < POROG_LINE) motor (100, 100);

}



void motor(int left_speed, int right_speed) {
  motor_left.setSpeed (left_speed, MOT_PWM);
  motor_right.setSpeed (right_speed, MOT_PWM);
}
