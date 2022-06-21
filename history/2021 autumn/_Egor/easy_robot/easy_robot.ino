// объявляем пины
#define PWMA 10 // пин для управления скоростью мотором А
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
  //danse();

  motor('B',255);
  motor('A',-255);
}

void loop(void) {
  //while(true);
}

void motor(char number, int speed) {
  if (number=='A') {
    analogWrite(PWMA,abs(speed));
    if (speed>0) digitalWrite(DIRA,1);
    else digitalWrite(DIRA,0);
  }
  if (number=='B') {
    
  }
}

/*
void danse() {
  motor(1,100);
  motor(2,100);
  delay(1000);
  motor(1,-100);
  motor(2,-100);
  delay(1000);
  
  motor(1,100);
  motor(2,100);
  delay(50);
  
  motor(1,100);
  motor(2,-100);
  delay(300);
  motor(1,-100);
  motor(2,100);
  delay(300);
  motor(1,100);
  motor(2,-100);
  delay(300);
  
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
}*/
