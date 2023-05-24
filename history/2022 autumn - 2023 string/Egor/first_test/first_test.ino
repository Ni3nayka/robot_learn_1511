const int LED = 3;
const int SENSOR = A2;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);
}

void loop() { // 300 970
  int data = analogRead(SENSOR);
  data = map(data,300,1000,0,255);
  analogWrite(LED,data);
  Serial.println( data );
  /*digitalWrite(LED,1);
  delay(1000);
  digitalWrite(LED,0);
  delay(1000);*/
  
  /*analogWrite(LED,0);
  delay(1000);
  analogWrite(LED,127);
  delay(1000);
  analogWrite(LED,255);
  delay(1000);*/
}
