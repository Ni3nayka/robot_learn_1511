const int led_pin = 10 ;
const int resp_pin = A5;


void setup() {
  pinMode(led_pin,OUTPUT);
  pinMode(resp_pin,INPUT);
  Serial.begin(9600);
}

void loop(){
  // 15 600
/*int r = analogRead(resp_pin);
int r1 = map(analogRead(resp_pin),15 ,583, 255,0);
r1 = constrain( map(analogRead(resp_pin),15 ,583, 255,0),0,255);
analogWrite(led_pin,r1);*/
analogWrite(led_pin,constrain( map(analogRead(resp_pin),15 ,583, 255,0),0,255));


Serial.println(constrain( map(analogRead(resp_pin),15 ,583, 255,0),0,255));


}









/*{
  analogWrite(led_pin,0);
  delay(500);
  analogWrite(led_pin,100);
  delay(500);
  analogWrite(led_pin,255);
  delay(500);
  analogWrite(led_pin,100);
  delay(500);
  analogWrite(led_pin,0);
  delay(500);*/


  
