#pragma once

#define PWM_A  5
#define DIR_A1 7
#define DIR_A2 8
#define DIR_B1 13
#define DIR_B2 12
#define PWM_B  6

void setup_motor (){
  pinMode(PWM_A, OUTPUT);
  pinMode(DIR_A1 , OUTPUT);
  pinMode( DIR_A2 , OUTPUT );

  pinMode(PWM_B, OUTPUT);
  pinMode(DIR_B1 , OUTPUT);
  pinMode(DIR_B2 , OUTPUT );

}



void  motor_a (int speed)
{
  if (speed > 0) {

    digitalWrite(DIR_A1, 1);
    digitalWrite(DIR_A2, 0);
  }
  else {

    digitalWrite(DIR_A1, 0);
    digitalWrite(DIR_A2, 1);
  }

  analogWrite( PWM_A , abs(speed) ) ;
}


void  motor_b (int speed)
{
  digitalWrite(DIR_B1, speed > 0);
  digitalWrite(DIR_B2, !(speed > 0));
  analogWrite( PWM_B , abs(speed) ) ;
}

void motor_ab (int a = 0 , int b = 0 , int delay_time = 0)
{
  a = constrain ( a , -255 , 255 );
  b = constrain( b , -255 , 255  );
  motor_a(a);
  motor_b(b);
  delay(delay_time);
}
