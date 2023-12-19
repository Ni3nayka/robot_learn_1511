#pragma once

#define PWM_A 10
#define DIR_A 12

#define PWM_B 11 
#define DIR_B 13

void setup_motor() {
  pinMode(PWM_A, OUTPUT);
  pinMode(DIR_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(DIR_B, OUTPUT);
}



void motor_a(int speed) {
  if (speed > 0) {
    digitalWrite(DIR_A, 1);

  }
  else {
    digitalWrite(DIR_A, 0);
  }
  analogWrite (PWM_A, abs (speed));
}

void motor_b(int speed) {
  digitalWrite(DIR_B, speed > 0);
  analogWrite (PWM_B, abs (speed));
}

void motor(int a = 0, int b = 0, int delay_time = 0) {
  a = constrain (a, -255, 255);
  b = constrain (b, -255, 255);
  motor_b(b);
  motor_a(a);
  delay(delay_time);
}
