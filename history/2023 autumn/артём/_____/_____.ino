const int led_pin = A5 ;
const int button_pin = 7;

void setup() {
  pinMode (led_pin, OUTPUT);
  pinMode (button_pin, INPUT);
  Serial.begin(9600);
}


void loop() {
  /*digitalWrite(led_pin, 1);
  delay(250);
  digitalWrite(led_pin, 0);
  delay(250);
  digitalWrite(led_pin, 1);
  delay(250);
  digitalWrite(led_pin, 0);
  delay(1000);*/
  int button = digitalRead(button_pin);
  Serial.println(button);
  if (button == 1)
  {

    digitalWrite(led_pin, 0);
  }
  else {
    digitalWrite(led_pin, 1) ;

  }


}
