// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  Serial.begin(9600);
  Serial.println("123\n\n\n123");

  /* motor(100, 100);
    delay (1000);
    motor(100, -100);
    delay (450);

    motor(100, 100);
    delay (1000);
    motor(100, -100);
    delay (450);

    motor(100, 100);
    delay (1000);
    motor(100, -100);
    delay (450);

    motor(100, 100);
    delay (1000);
    motor(100, -100);
    delay (450);

    motor_left.setSpeed (0, MOT_PWM);
    motor_right.setSpeed (0, MOT_PWM);


    }
    int i = 0;*/
}
void loop() {
  if (Serial.available() > 0) {
    char symbol = Serial.read();
    if (symbol == 'S') motor (0, 0);
    if (symbol == 'B') motor  (-100, -100);
    if (symbol == 'L') motor (100, 0);
    if (symbol == 'R') motor  (0, 100);
    if (symbol == 'F') motor  (100, 100);
    if (symbol == 'J') motor  (-100, 50);
    if (symbol == 'H') motor (50, -100);
    if (symbol == 'I') motor  (50, 100);
    if (symbol == 'G') motor  (100, 50);
  }
  /*  if (i == 0) {
      i = i + 1;

      motor(100, 100);
      delay (1000);
      motor_left.setSpeed (100, MOT_PWM);
      motor_right.setSpeed (-100, MOT_PWM);
      delay (450);
      motor(-100, -100);
      delay(500);
      motor_left.setSpeed (0, MOT_PWM);
      motor_right.setSpeed (0, MOT_PWM);

    }
  */
}



void motor(int left_speed, int right_speed) {
  motor_left.setSpeed (left_speed, MOT_PWM);
  motor_right.setSpeed (right_speed, MOT_PWM);
}
