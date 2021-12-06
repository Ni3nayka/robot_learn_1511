// объявляем пины
#define PWMA 10
#define DIRA 12
#define PWMB 11
#define DIRB 13

void setup() {
  // запускаем пины
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB, OUTPUT);
  // запускаем процедуру танца
  /*motor(1,255);
  motor(2,255);
  delay(1000);
  motor(1,0);
  motor(2,0);*/
  danse();
}

void loop() {
  //while(true);
}

void danse() {
  /*motor(1,255);
  motor(2,255);
  delay(500);
  motor(1,-255);
  motor(2,-255);
  delay(500);
  motor(1,-255);
  motor(2,255);
  delay(500);
  motor(1,255);
  motor(2,-255);
  delay(500);*/
  motor(1,100);
  motor(2,100);
  delay(1000);
  for (int i=0; i<3; i++) {
    motor(1,255);
    motor(2,80);
    delay(600);
    motor(1,12);
    motor(2,255);
    delay(600);
  }
  motor(1,0);
  motor(2,0);
}

void motor(int number, int speed) {
  if (number==1) {
    analogWrite(PWMA, abs(speed) );
    digitalWrite(DIRA, speed>0 );
  }
  else {
    analogWrite(PWMB, abs(speed) );
    digitalWrite(DIRB, speed>0 );
  }
}
