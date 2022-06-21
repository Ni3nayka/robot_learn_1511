void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  pinMode(A2,INPUT_PULLUP);
  pinMode(A3,INPUT_PULLUP);
  pinMode(A4,INPUT_PULLUP);
}

void loop() {
  Serial.print(!digitalRead(A0));
  Serial.print(!digitalRead(A1));
  Serial.print(!digitalRead(A2));
  Serial.print(!digitalRead(A3));
  Serial.println(!digitalRead(A4));

  if (digitalRead(A0)==0){tone(9,500);}
  else if (!digitalRead(A1)){tone(9,1000);}
  else if (!digitalRead(A2)){tone(9,1500);}
  else if (!digitalRead(A3)){tone(9,2000);}
  else if (!digitalRead(A4)){tone(9,2500);}
  else noTone(9);
}
