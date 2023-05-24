const int PWMA = 10;
const int PWMB = 11;
const int DIRA = 12;
const int DIRB = 13;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  bobik(100, 100);
  delay(2000);
  bobik(-150, -150);
  delay(2000);
  bobik(0, 0);
}

void loop() {

}


void bobik(int speed_a, int speed_b) {
  analogWrite(PWMA, abs (speed_a));
  analogWrite(PWMB, abs (speed_b));
  
  if (speed_a > 0) 
    digitalWrite(DIRA, 1);
  
  else {
    digitalWrite(DIRA, 0);
  }

  digitalWrite(DIRB,speed_b > 0 );
}
