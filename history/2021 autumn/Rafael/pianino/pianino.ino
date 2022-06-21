int button [5] = {9,8,10,11,12};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);
  pinMode(button[3], INPUT_PULLUP);
  pinMode(button[4], INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(button[0]));
  Serial.print(digitalRead(button[1]));
  Serial.print(digitalRead(button[2]));
  Serial.print(digitalRead(button[3]));
  Serial.println(digitalRead(button[4]));


  if (digitalRead(button[0])==0) {
    tone(6, 500);
  }
  else if (digitalRead(button[1])==0) {
    tone(6, 1000);
  }
  else if (!digitalRead(button[2])) {
    tone(6, 1500);
  }
  else if (!digitalRead(button[3])) {
    tone(6, 2000);
  }
  else if (!digitalRead(button[4])) {
    tone(6, 2500);    
  }
  else{noTone(6);
  }
}
