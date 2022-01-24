#define PWMA 10
#define DIRA 12
#define PWMB 11
#define DIRB 13 
void setup() {
  // put your setup code here, to run once:
  // запускаем пины
  pinMode(PWMA,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  pinMode(DIRB,OUTPUT);
Serial.begin(9600);
}

void loop() {
 if (Serial.available()){
 char input = Serial.read();
 if(input=='S') motors(0,0);
 if(input=='F') motors(225,225);
 if(input=='B') motors(-225,-225);
 if(input=='R') motors(225,-225);
 if(input=='L') motors(-225,225);
}
 }
void motor(char number,int speed){
  if (number=='A'){
    analogWrite(PWMA,abs(speed));
    if (speed>0)digitalWrite(DIRA,1);
    else digitalWrite(DIRA,0); 
  }
  if (number=='B'){
      analogWrite(PWMB,abs(speed));
    if (speed>0)digitalWrite(DIRB,1);
    else digitalWrite(DIRB,0);
}
}
void motors(int speed_a,int speed_b) {
motor('A',speed_a);
motor('B',speed_b);
}
