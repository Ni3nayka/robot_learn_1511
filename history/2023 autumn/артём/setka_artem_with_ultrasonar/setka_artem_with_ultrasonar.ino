#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);
int black_line = 1800;
float speed_0;
int e ;
float kp = 0.05;
int u = 0;
const int trigPin = 12; // назначаем имя для pin9
const int echoPin = 11; // назначаем имя для pin8


void setup() {
  delay(500);
  pinMode(trigPin, OUTPUT); // назначаем trigPin, как выход
  pinMode(echoPin, INPUT);  // назначаем echoPin, как вход
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  Serial.begin(9600);
  for ( int i = 0 ; i < 1 ; i ++ )
  {
    forward ();
  }

  cheking ();
  cheking ();
  cheking ();
  cheking ();
  turn_right();
  turn_right();
  for (int i = 0 ; i < 4 ; i ++ )
  {
    forward ();
  }
  motor( 100 , 100 );
  delay ( 300 );
  motor( 0, 0 );
}







void loop() {
  // int l = bum.getLineAnalog(3); // белое - 2700  черное - 330
  //Serial.println( get_ultrasonar() );


}

void forward ()
{
  while ( bum.getLineAnalog(1) > black_line and bum.getLineAnalog(9) > black_line )
  {
    PPP ();
  }
  /* motor ( 100, 100 );
    delay ( 500 );*/
  unsigned long  int t = millis () + 500 ;
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

int get_ultrasonar()
{
  int duration = 0 , cm = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  cm = duration / 58; // вычисляем расстояние в сантиметрах
  //Serial.print(cm);
  //Serial.println(" cm");
  delay(50);
  return cm;
}

void cheking ()
{
  for ( int i = 0 ; i < 1 ; i++ )
  {
    forward();
  }
  for (int i = 0 ; i < 1 ; i ++ )
  {
    turn_left();
  }
  if ( get_ultrasonar () < 20 and get_ultrasonar () > 0 )
  {
    forward();
    turn_left();
    turn_left();
    forward();
  }
  else {
    turn_right();
    turn_right();
  }
  if ( get_ultrasonar () < 20 and get_ultrasonar () > 0 )
  {
    forward();
    turn_left();
    turn_left();
    forward();
    turn_right();
  }
  else
  {
    turn_left();
  }

  /* if ( get_ultrasonar () < 20 and get_ultrasonar () > 0 )
    {
     forward();
     turn_left();
     turn_left();
     forward();
     turn_right();*/

}
