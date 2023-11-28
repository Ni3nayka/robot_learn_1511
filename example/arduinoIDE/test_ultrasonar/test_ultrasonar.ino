int trigPin = 9; // назначаем имя для pin9
int echoPin = 8; // назначаем имя для pin8
 
void setup() { 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); // назначаем trigPin, как выход
  pinMode(echoPin, INPUT);  // назначаем echoPin, как вход
} 
 
void loop() { 
  int duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  cm = duration / 58; // вычисляем расстояние в сантиметрах
  Serial.print(cm);
  Serial.println(" cm");

  delay(1000);
}
