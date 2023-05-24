const int PWMA = 10;
const int PWMB = 11;
const int DIRA = 12;
const int DIRB = 13;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
 
}

void loop() {
  if (Serial.available()>0) {
    char sosiska = Serial.read();
    Serial.println(sosiska);
    if (sosiska=='F') bobik(125, 125);
    if (sosiska=='B') bobik(-125,-125);
    if (sosiska=='L') bobik(-200,200);
    if (sosiska=='R') bobik(200,-200);
    if (sosiska=='G') bobik(25,150);
    if (sosiska=='I') bobik(150,25);
    if (sosiska=='H') bobik(11,125);
    if (sosiska=='J') bobik(125,11);
    if (sosiska=='S') bobik(0,0);
   if (sosiska=='V') tone(4, 1000); 
    if (sosiska=='v') noTone(4);
  }

}


void bobik(int speed_a, int speed_b) {
  analogWrite(PWMA, abs (speed_a));
  analogWrite(PWMB, abs (speed_b));
   if (speed_a>0) {
    digitalWrite(DIRA,1);
   }
   else {
    digitalWrite(DIRA,0);
   }
  digitalWrite(DIRB, speed_b>0);
}

  
