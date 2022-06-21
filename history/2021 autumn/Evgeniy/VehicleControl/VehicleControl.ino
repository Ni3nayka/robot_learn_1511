#define PWMA 10 
#define DIRA 12
#define PWMB 11
#define DIRB 13
int maxSpeed = 255;

void setup() {
  pinMode (PWMA, OUTPUT);
  pinMode (DIRA, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (DIRB, OUTPUT);

  /*analogWrite (PWMA, 255);
  digitalWrite (DIRA, 1);
  analogWrite (PWMB, 255);
  digitalWrite (DIRB, 1);
  delay (3000);
  analogWrite (PWMA, 0);
  digitalWrite (DIRA, 1);
  analogWrite (PWMB, 0);
  digitalWrite (DIRB, 1);
  delay (1000);
  analogWrite (PWMA, 180);
  digitalWrite (DIRA, 0);
  analogWrite (PWMB, 180);
  digitalWrite (DIRB, 0);
  delay (3000);
  analogWrite (PWMA, 0);
  digitalWrite (DIRA, 1);
  analogWrite (PWMB, 0);
  digitalWrite (DIRB, 1);*/

  motor (1, 255);
  motor (2, 255);
  delay (700);
  motor (1, -255);
  motor (2, 255);
  delay(1000);
  motor (1, -255);
  motor (2, -255);
  delay(700);
  motor (1, 255);
  motor (2, -255);
  delay(1000);
  motor (1, 255);
  motor (2, 255);
  delay(1000);
  motor (1, 0);
  motor (2, 0);
  delay(1000);
  motor (1, -255);
  motor (2, -180);
  delay(1000);
  motor (1, 180);
  motor (2, 255);
  delay(1000);
  motor (1, 0);
  motor (2, 255);
  delay(400);
  motor (1, 255);
  motor (2, 0);
  delay(1000);
  motor (1, 0);
  motor (2, 0);
  delay(1000);
  motor (1, 255);
  motor (2, 255);
  delay(250);
  motor (1, -255);
  motor (2, -255);
  delay(250);
  motor (1, 255);
  motor (2, 255);
  delay(250);
  motor (1, -255);
  motor (2, -255);
  delay(250);
  motor (1, -255);
  motor (2, -255);
  delay(250);
  motor (1, 255);
  motor (2, 255);
  delay(250);
  motor (1, -255);
  motor (2, -255);
  delay(250);
  motor (1, 255);
  motor (2, 255);
  delay(250);
  motor (1, -255);
  motor (2, -255);
  delay(250);
  motor (1, 0);
  motor (2, 0);
  
}

void motor(int number, int speed) {
  if (number == 1){
    analogWrite(PWMA, abs(speed));
    digitalWrite(DIRA, (speed > 0));}
  if (number == 2){
    analogWrite(PWMB, abs(speed));
    digitalWrite(DIRB, (speed > 0));}
}

void loop(){}
