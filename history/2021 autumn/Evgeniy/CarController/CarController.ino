#define PWMA 10 
#define DIRA 12
#define PWMB 11
#define DIRB 13
int maxSpeed = 255;
int s = 255;
void setup() {
  pinMode (PWMA, OUTPUT);
  pinMode (DIRA, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (DIRB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char S = Serial.read();
    if (S == 'F') forward();
    if (S == 'S') stop_motor();
    if (S == 'B') back();
    if (S == 'L') left();
    if (S == 'R') right();
    if (S == '0')
      s = 100;
    if (S == '1')
      s = 115;
    if (S == '2')
      s = 130;
    if (S == '3')
      s = 145;
    if (S == '4')
      s = 160;
    if (S == '5')
      s = 175;
    if (S == '6')
      s = 190;
    if (S == '7')
      s = 205;
    if (S == '8')
      s = 220;
    if (S == '9')
      s = 235;
    if (S == 'q')
      s = 250;
  }
}

void motor(int number, int speed) {
  if (number == 1){
    analogWrite(PWMA, abs(speed));
    digitalWrite(DIRA, (speed > 0));
  }
  if (number == 2){
    analogWrite(PWMB, abs(speed));
    digitalWrite(DIRB, (speed > 0));
  }
}
void forward(){
  motor(1, s);
  motor(2, s);
}

void stop_motor(){
motor(1, 0);
motor(2, 0);
}

void back(){
motor(1, -s);
motor(2, -s);
}

void left(){
motor(1, -s);
motor(2, s);
}

void right(){
motor(1, s);
motor(2, -s);
}
