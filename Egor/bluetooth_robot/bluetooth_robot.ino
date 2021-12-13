// объявляем пины
#define PWMA 10 // пин для управления скоростью мотором А
#define DIRA 12
#define PWMB 11
#define DIRB 13

void setup() {
  Serial.begin(9600);
  // запускаем пины
  pinMode(PWMA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRB, OUTPUT);
  // запускаем процедуру танца
  motors(0,0);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();
    if (input=='S') motors(0,0);
    if (input=='F') motors(255,255);
    if (input=='B') motors(-255,-255);
    if (input=='L') motors(-255,255);
    if (input=='R') motors(255,-255);
  }
}

void motors(int speed1,int speed2) {
  motor(1,speed1);
  motor(2,speed2);
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
