#include "constant.h"

#define DEBUG 0

int history[mas_size] = {0};
int M = 0;
unsigned long int time = 0;
const int button = 8;

bool read(){
  return !digitalRead(button);
  }

void setup(){
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  }  

void loop(){
  time = millis();
  while (read()) delay(50);
  if (millis()-time > 500){
    Serial.println("_");
    
  }
  if (millis()-time >= 10 && millis()-time < 500){
    Serial.println(".");
  }
  }
