const int led_pin = A3;
const int button_pin = 9;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}
void loop() {
  /*digitalWrite(led_pin,1);
    delay(500);
    digitalWrite(led_pin,0);
    delay(500);*/
  /*int button = digitalRead(button_pin);
  //Serial.println(button);
  if (button == 0) {
    digitalWrite(led_pin, 1);
  }
  else {
    digitalWrite(led_pin, 0);
  }*/

  int button = digitalRead(button_pin);
  if (button == 0) {
    digitalWrite(led_pin, 1);
  }
  else {
    digitalWrite(led_pin, 0);
  }
}
