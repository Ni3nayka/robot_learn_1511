// подключаем файл с константами
#include "constant.h"

void setup() {
  Serial.begin(9600);
  
  pinMode(spiker,OUTPUT);
  return;
  tone(spiker,sound);
  delay(tire);
  noTone(spiker);
}

void loop() {
  if (Serial.available()) {
    char bykva = Serial.read();
    if (bykva=='A') speak(azbuka[0]);
  }
}

void speak(int mas[mas_size]) {
   // если это буква 'А', то: mas = {0,1,2,0,0,0,0}
   if (mas[0]==0) {/* точка */ }
   else if (mas[0]==1) {/* тире */ }
   else return;

   if (mas[1]==0) {/* точка */ }
   else if (mas[1]==1) {/* тире */ }
   else return;

   
}
