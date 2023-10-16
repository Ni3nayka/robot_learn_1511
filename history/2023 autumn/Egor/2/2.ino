const int led_pin = 10;
const int resp_pin = A5;
void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode (resp_pin, INPUT);
  Serial. begin (9600);
}

void loop() {
  // 50 900
  /*int r = analogRead (resp_pin);
  int r1 = map (r,50,600 ,255, 0);
  r1 = constrain (r1, 0, 255);
  analogWrite (led_pin, r1);
  Serial. println (r1);*/

  analogWrite (led_pin, constrain ( map ( analogRead (resp_pin), 50, 600, 255, 0), 0, 255));
  
}
