const int left_speed = 11;
const int left_dir = 13;
const int right_speed = 10;
const int right_dir = 12;
void setup() {
  Serial.begin (9600);
  pinMode (right_speed , OUTPUT);
  pinMode (left_dir , OUTPUT);
  pinMode (left_speed , OUTPUT);
  pinMode (right_dir , OUTPUT);
  analogWrite (left_speed, 60);
  analogWrite (right_speed, 60);
}

void loop() {
  //distanse
  int d = (analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) ) ;
  d /= 5;
  int distanse = 32 * pow(d * 0.0048828125, -1.10);
  // Serial.println(distanse);
  int linia = analogRead(A0);
  // Serial.println(linia);
  digitalWrite(left_dir, 1);
  digitalWrite(right_dir, 1);
  while (distanse > 15) {
    d = (analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) + analogRead(A1) ) / 5;
    distanse = 32 * pow(d * 0.0048828125, -1.10);
    Serial.println(distanse);
  }  digitalWrite(left_dir, 0);
  digitalWrite(right_dir, 0);
  delay(300);
  digitalWrite(left_dir, 1);
  digitalWrite(right_dir, 0);
  delay(1000);
  digitalWrite(left_dir, 0);
  digitalWrite(right_dir, 1);
  delay(1000);
}
