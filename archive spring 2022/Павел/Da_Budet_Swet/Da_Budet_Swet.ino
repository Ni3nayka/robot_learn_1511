/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board

const int swet = 13;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(swet, OUTPUT);
  pinMode(A2, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  /*analogWrite(swet, 250);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  analogWrite(swet, 200);    
  delay(500);            
  analogWrite(swet, 150);    
  delay(500);     
  analogWrite(swet, 100);    
  delay(500);     
  analogWrite(swet, 50);    
  delay(500);   
  analogWrite(swet, 0);    
  delay(500);*/
  int a = digitalRead(A2);
  //Serial.println(a);
  digitalWrite(swet, !a);
}
