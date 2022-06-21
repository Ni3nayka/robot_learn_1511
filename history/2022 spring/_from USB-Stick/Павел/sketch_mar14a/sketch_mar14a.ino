#include <SoftwareSerial.h>

SoftwareSerial bluetooth(3, 2);

void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char t = bluetooth.read();
    if (t=='H') digitalWrite(11, 1);
    if (t=='L') digitalWrite(11, 0);
    if (t=='1') {
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
    }
    if (t=='2') {
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
    }
    if (t=='3') {
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
      digitalWrite(11, 1);
      delay(100);
      digitalWrite(11, 0);
      delay(100);
    }
  }
}
