const int PWMA = 10;
const int DIRA = 12;
const int PWMB = 11;
const int DIRB = 13;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode (DIRA, OUTPUT);
  pinMode (PWMB, OUTPUT);
  pinMode (DIRB, OUTPUT);
  Serial.begin(9600);




}

void loop() {
 if (Serial.available() > 0) {
    char f = Serial.read();
   //Serial.println (f);
 if (f=='F') motor (220,220);
 if (f=='S') motor (0,0);
 if (f=='B') motor (-120,-120);
 if (f=='R') motor (155,-155);
 if (f=='L') motor (-155,155);
 if (f=='G') motor (0,155);
 if (f=='I') motor (155,0);
 if (f=='H') motor (-155,0);
 if (f=='J') motor (0,-155);


   
  }







}
void motor(int a, int b) {
  if (a > 0) {
    digitalWrite( DIRA, 1) ;
    analogWrite (PWMA, a);
  }
  else {
    digitalWrite( DIRA, 0) ;
    analogWrite (PWMA, -a);
  }
  if (b > 0) {
    digitalWrite( DIRB, 1) ;
    analogWrite (PWMB, b);
  }
  else {
    digitalWrite( DIRB, 0) ;
    analogWrite (PWMB, -b);
  }
}
