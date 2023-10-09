const int led_pin = 5;

void setup() {
  pinMode(led_pin,OUTPUT);
}

void loop() {
  for (int i = 0; i<255; i++) {
    analogWrite(led_pin,i);
    delay(5);
  }
}
