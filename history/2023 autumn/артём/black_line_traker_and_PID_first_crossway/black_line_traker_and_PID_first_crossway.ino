// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):

#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_left(0x0B);
iarduino_I2C_Motor mot_right(0x0A);
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);
long int i = 0;
int e_old = 0 ;
bool f = 1;
int counter = 0;

void setup() {

  delay(500);
  bum.begin();
  mot_left.begin();
  mot_right.begin();
  mot_left.setDirection(false);
  mot_right.setDirection(true);

  Serial.begin(9600);
}

#define POROG_LINE 1500
#define KP 0.034
#define KI 0.0015
#define KD 0.0001
#define M0 100

void loop()
{
  if (bum.getLineAnalog(3) > POROG_LINE or bum.getLineAnalog(7) > POROG_LINE  ) {
    if ( f == 0 ) {
      motor ( 100, 100 );
      delay( 300 );
    }
    f = 1;
    run_pid();
  }
  else {
    if (f == 1) {
      f = 0 ;
      counter ++;
      if ( counter == 4 ) {
        motor( -100, -100 );
        delay (80);
        f = 0;
        motor ( 0, 0 );
        while (1);

      }
    }
    motor ( 100 , 100 );
  }

}



void motor(int left_speed, int right_speed) {
  mot_left.setSpeed(left_speed, MOT_PWM);
  mot_right.setSpeed(right_speed, MOT_PWM);
}
void run_pid() {
  int z = bum.getLineAnalog(3);
  int x = bum.getLineAnalog(7);
  //  Serial.println(q);
  //  Serial.println(p);
  int e = z - x;
  int p = e;
  i = e + i * 0.95 ;
  int d = e - e_old;
  e_old = e;
  int pid = p * KP + i * KI + d * KD;
  motor ( M0 + pid, M0 - pid );
}
