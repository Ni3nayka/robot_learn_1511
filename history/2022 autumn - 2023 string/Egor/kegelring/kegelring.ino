/*#define SP 10 
#define DP 12
#define SL 11
#define DL 13*/

const int left_speed = 11;
const int left_dir = 13; 
const int right_speed = 10;
const int right_dir = 12; 

void setup() {
  Serial.begin(9600);
  pinMode(left_speed,OUTPUT);
  pinMode(left_dir,OUTPUT);
  pinMode(right_speed,OUTPUT);
  pinMode(right_dir,OUTPUT);
  
    analogWrite(left_speed,255);
    analogWrite(right_speed,255);
}

void loop() {
  // distanse
  int d = analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1);
  d = d/5;
  int distanse = 32*pow(d*0.0048828125, -1.10);
  //Serial.println(distanse);
  int linia = analogRead(A0);
  //Serial.println(linia);
  // linia>200 - черное
    digitalWrite(left_dir,1);
    digitalWrite(right_dir,0);
  while (distanse>30) {
    
    d = analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1);
    d = d/5;
    distanse = 32*pow(d*0.0048828125, -1.10);
  }
    digitalWrite(left_dir,1);
    digitalWrite(right_dir,0);
    delay(1000);
    digitalWrite(left_dir,1);
    digitalWrite(right_dir,0);
}
