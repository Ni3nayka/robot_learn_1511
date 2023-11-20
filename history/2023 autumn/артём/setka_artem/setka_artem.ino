#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);
int black_line = 1515;
float speed_0;
int e ;
float kp = 0.05;
int u = 0;


void setup() {
  delay(500);
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);
  while ( u < 5 )
  {
    forward ();
    u++;
  }
  turn_left();
  for ( int a = 0 ; a < 2; a++)
  {
    forward();
  }
  for ( int x = 0; x < 2 ; x++)
  {
    turn_left();
  }
  for ( int m = 0 ; m < 4; m ++ )
  {
    forward () ;
  }
  for ( int m = 0 ; m < 1; m ++ )
  {
    turn_right () ;
  }
    forward () ;
    for ( int m = 0 ; m < 1; m ++ )
  {
    turn_right () ;
  }
  for ( int m = 0 ; m < 2; m ++ )
  {
    forward () ;
  }
  for ( int m = 0 ; m < 1; m ++ )
  {
    turn_left() ;
  }
 for ( int m = 0 ; m < 3; m ++ )
  {
    forward () ;
  }
  motor( 100,100 );
  delay ( 500 );
  motor( 0,0 );
  
  

}

void loop() {
  // int l = bum.getLineAnalog(3); // белое - 2700  черное - 330

}

void forward ()
{
  while ( bum.getLineAnalog(1) > black_line and bum.getLineAnalog(9) > black_line )
  {
    PPP ();
  }
  /* motor ( 100, 100 );
    delay ( 500 );*/
  unsigned long  int t = millis () + 450 ;
  while ( t > millis() )
  {
    PPP ();
  }
  motor ( 0 , 0 );

}

void turn_left ()
{
  while ( bum.getLineAnalog(3) < black_line )
  {
    motor ( -100 , 100 );

  }
  while ( bum.getLineAnalog(3) > black_line )
  {
    motor ( -100 , 100 );

  }
  while ( bum.getLineAnalog(3) < black_line )
  {
    motor ( -100 , 100 );
  }
  motor ( 100 , -100 );
  delay ( 50 );
  motor( 0, 0 );
}

void turn_right ()
{
  while ( bum.getLineAnalog(7) < black_line )
  {
    motor ( 100 , -100 );

  }
  while ( bum.getLineAnalog(7) > black_line )
  {
    motor ( 100 , -100 );

  }
  while ( bum.getLineAnalog(7) < black_line )
  {
    motor ( 100 , -100 );
  }
  motor ( -100 , 100 );
  delay ( 50 );
  motor( 0, 0 );
}


void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}

void PPP ()
{
  e = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  int    p = e * kp;
  speed_0 = 100;
  int  m1 = speed_0 + p;
  int  m2 = speed_0 - p;
  motor( m1 , m2 );
}
