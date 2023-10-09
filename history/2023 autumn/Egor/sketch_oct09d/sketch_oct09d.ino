const int led_pin = 6;
void setup() {
  pinMode (led_pin,OUTPUT);

}

void loop() {
  analogWrite(led_pin,0);
  delay (1000);
  analogWrite (led_pin,100);
  delay (1000);
  analogWrite ( led_pin,255);
  delay (1000);
  
}
