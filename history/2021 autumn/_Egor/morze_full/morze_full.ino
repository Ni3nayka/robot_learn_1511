// подключаем файл с константами
#include "constant.h"

#define DEBUG 0

int history[mas_size] = {0};
int M = 0;
unsigned long int time = 0;
const int button = 5;

bool read() {
  return !digitalRead(button);
}

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  time = millis();
  while (!digitalRead(4)) delay(50);
  unsigned long int time_tap = millis()-time;
  if (time_tap>10 && time_tap<500) Serial.println(".");
  if (time_tap>10 && time_tap>=500)Serial.println("-");
  /*time = millis();
  while (read()) delay(50);
  if (millis()>time+10) {
    if (millis()-time>500) {
      if (DEBUG) Serial.print("-");
      history[M] = 1;
      M++;
    }
    else {
      if (DEBUG) Serial.print(".");
      history[M] = 0;
      M++;
    }
  }

  time = millis();
  while (!read() && millis()-time<1000) delay(50);
  if (millis()-time>1000 && M>0) {
    if (DEBUG) Serial.println();
    history[M] = 2;
    if (DEBUG) {
      for (int i = 0; i<mas_size; i++) 
        Serial.print(history[i]);
      Serial.println();
    }

    for (int i = 0; i<26; i++) {
      bool flag = true;
      for (int u = 0; u<7; u++) {
        if (azbuka[i][u]!=history[u]) {
          flag = false;
          break;
        }
      }

      if (flag==true) {
        Serial.println(azbuka_s[i]);
        break;
      }
    }
    
    for (int i = 0; i<mas_size; i++) 
      history[i] = 0;
    M = 0;
  }*/
}
