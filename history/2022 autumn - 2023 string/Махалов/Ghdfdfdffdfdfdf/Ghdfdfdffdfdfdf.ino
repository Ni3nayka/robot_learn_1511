/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //  myservo.write(85);
  //  delay(5000);
  //  myservo.write(12);
  //  delay(3000);
  if (analogRead(A5) > 400) {
    myservo.write(85);
    delay(2500);
    myservo.write(12);
                  delay(3000);
  }
  else {
    myservo.write(20);
  }
}
// waits 15 ms for the servo to reach the position
