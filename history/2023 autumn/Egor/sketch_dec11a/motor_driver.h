#pragma once

#define PWM_A 5 // enable pin
#define DIR1_A 2
#define DIR2_A 3

#define PWM_B 6 // enable pin
#define DIR1_B 7
#define DIR2_B 8

void setup_motor() {
  pinMode(PWM_A, OUTPUT);
  pinMode(DIR1_A, OUTPUT);
  pinMode(DIR2_A, OUTPUT);
  pinMode(PWM_B, OUTPUT);
  pinMode(DIR1_B, OUTPUT);
  pinMode(DIR2_B, OUTPUT);
}



void motor_a(int speed) {
  if (speed > 0) {
    digitalWrite(DIR1_A, 1);
    digitalWrite(DIR2_A, 0);

  }
  else {
    digitalWrite(DIR1_A, 0);
    digitalWrite(DIR2_A, 1);
  }
  analogWrite (PWM_A, abs (speed));
}

void motor_b(int speed) {
  digitalWrite(DIR1_B, speed > 0);
  digitalWrite(DIR2_B, speed < 0);
  analogWrite (PWM_B, abs (speed));
}

void motor(int a = 0, int b = 0, int delay_time = 0) {
  a = constrain (a, -255, 255);
  b = constrain (b, -255, 255);
  motor_b(b);
  motor_a(a);
  delay(delay_time);
}
