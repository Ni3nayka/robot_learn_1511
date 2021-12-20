// объявляем пины
#define PWMA 10 // пин для управления скоростью мотором А
#define DIRA 12 // пин для управления направлением вращения мотора А
#define PWMB 11 // пин для управления скоростью мотором B
#define DIRB 13 // пин для управления направлением вращения мотора B

void setup() {
  // запускаем пины
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB, OUTPUT);
  // запускаем процедуру танца
  danse();
}

// процедура управляющая только одним мотором
void motor(char number, int speed) {
  if (number=='A') {              // управление левым мотором
    analogWrite(PWMA,abs(speed)); // запуск мотора со скоростью speed
    digitalWrite(DIRA,speed>0);   // запуск мотора в направлении знака speed
  }
  if (number=='B') {              // управление левым мотором
    analogWrite(PWMB,abs(speed)); // запуск мотора со скоростью speed
    digitalWrite(DIRB,speed>0);   // запуск мотора в направлении знака speed
  }
}


void loop() {
  
}

void danse() {
  motors(255,255); 
  delay(1000);
  motors(-255,-255); 
  delay(1000);
  motors(-255,255); 
  delay(500);
  motors(255,-255); 
  delay(500);
  motors(0,0); 
}

// процедура управляющая сразу двумя моторами
void motors(int speed_a, int speed_b) { 
  motor('A',speed_a);
  motor('B',speed_b);
}
