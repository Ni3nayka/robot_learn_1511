const int trigPin = 12; // назначаем имя для pin9
const int echoPin = 11; // назначаем имя для pin8
#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motor_left(0x0B);
iarduino_I2C_Motor motor_right(0x0A);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0D);

void setup() {
  delay(500);
  pinMode(trigPin, OUTPUT); // назначаем trigPin, как выход
  pinMode(echoPin, INPUT);  // назначаем echoPin, как вход
  motor_left.begin();
  motor_right.begin();
  motor_left.setDirection(0);
  motor_right.setDirection(1);
  bum.begin();
  get_ultrasonar();
  Serial.begin(9600);
  // motor(100, 100);
  // delay(200);
  // motor(0, 0);
  forward();
  forward();
  track();
  forward();
  track();
  forward();
  track();
  forward();
  track();
  turn_right();
  turn_right();
  forward();
  forward();
  forward();
  forward();
  motor(100, 100);
   delay(200);
   motor(0, 0);
}

void track() {
  turn_left();
  int cm = get_ultrasonar();
  if (cm > 30) {
    turn_left();
    turn_left();
  }
  else {
    forward();
    turn_left();
    turn_left();
    forward();
  }
  cm = get_ultrasonar();
  if (cm > 30) {
    turn_left();
  }
  else {
    forward();
    turn_right();
    turn_right();
    forward();
    turn_right();
  }
  
}
void loop() {
  // int A = bum.getLineAnalog(3); // белое - 2700  черное - 330
  //  int B = bum.getLineAnalog(7);
  // int e = A - B;
  // int P = e*0.05;
  // int left = 100 + P;
  //  int right = 100 - P;
  //  motor (left, right);
  // p_regulator();

}
int LINE_POROG = 2000;

void turn_left() {
  motor(-100, 100);
  while (bum.getLineAnalog(3) < LINE_POROG);
  while (bum.getLineAnalog(3) > LINE_POROG);
  while (bum.getLineAnalog(3) < LINE_POROG);
  motor(100, -100);
  delay(50);
  motor(0, 0);
}

void turn_right() {
  motor(100, -100);
  while (bum.getLineAnalog(7) < LINE_POROG);
  while (bum.getLineAnalog(7) > LINE_POROG);
  while (bum.getLineAnalog(7) < LINE_POROG);
  motor(-100, 100);
  delay(50);
  motor(0, 0);
}


void forward () {
  while (bum.getLineAnalog(0) > 1500 && bum.getLineAnalog(9) > 1500) {
    p_regulator();

  }
  // motor(100, 100);
  //delay (480);
  unsigned long int t = millis() + 450;
  while (t > millis()) {
    p_regulator();
  }
  motor(0, 0);
}

void p_regulator () {
  int A = bum.getLineAnalog(3); // белое - 2700  черное - 330
  int B = bum.getLineAnalog(7);
  int e = A - B;
  int P = e * 0.05;
  int left = 100 + P;
  int right = 100 - P;
  motor (left, right);
}
void motor(int left_speed, int right_speed) {
  motor_left.setSpeed(left_speed, MOT_PWM);
  motor_right.setSpeed(right_speed, MOT_PWM);
}
int get_ultrasonar() {
  int duration, cm;

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
