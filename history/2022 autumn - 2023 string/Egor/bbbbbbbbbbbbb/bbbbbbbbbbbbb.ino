int cm = 0;

const int PIN_TRIG = 50;
const int PIN_ECHO = 52;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  distanse();
  Serial.println(cm);
}

void distanse() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  int duration = pulseIn(PIN_ECHO, HIGH);
  cm = (duration / 2) / 29.1;
  delay(250);
}
