#include "motor_driver.h"

void setup() { 
  Serial.begin(9600);
  setup_motor();
//  motor(256,256, 2000);
//  motor();
}

void loop() {
  if (Serial.available()>0) {
      char f = Serial.read();
      if (f=='F') motor(256,256);
      if (f=='S') motor(0,0);
      if (f=='B') motor(-256,-256);
      if (f=='L') motor(-256,256);
      if (f=='R') motor(256,-256);
      //if (f=='R') motor(256,-256);
      // 
  }
}


