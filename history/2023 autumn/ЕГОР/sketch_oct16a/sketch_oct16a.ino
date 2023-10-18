const int led_pin = 9;
const int resp_pin = A5;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(resp_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 50 620
  int r = analogRead(resp_pin);
  int r1 = map(r, 50,620, 255,0);
  r1 = constrain(r1,0,255);
  analogWrite(led_pin, r1);
  Serial.println(r1);
}
