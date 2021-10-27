// подключаем файл с константами
#include "constant.h"

void setup() {
  /*speak(azbuka[0]); // передаем в процедуру букву 'А'
    pinMode(spiker,OUTPUT);
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(tire);
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(tire);
    tone(spiker, sound);
    delay(microTire);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire);
    noTone(spiker);
    delay(tire);
    noTone(spiker);
    delay(tire);
    tone(spiker, sound);
    delay(microTire2);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire2);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire2);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire2);
    noTone(spiker);
    delay(microTire);
    noTone(spiker);
    delay(tire);
    tone(spiker, sound);
    delay(microTire);
    noTone(spiker);
    delay(microTire);
    tone(spiker, sound);
    delay(microTire);
    noTone(spiker);
    delay(microTire);*/
  speak(azbuka[0]);
  Serial.begin(9600);
  pinMode (spiker, OUTPUT);
  return;
  tone(spiker, sound);
  delay(tire);
  noTone(spiker);
}

void loop() {
  if (Serial.available()) {
    char bykva = Serial.read();
    if (bykva == 'A') speak(azbuka[0]);
    if (bykva == 'B') speak(azbuka[1]);
    if (bykva == 'C') speak(azbuka[2]);
    if (bykva == 'D') speak(azbuka[3]);
  }

}

void speak(int mas[mas_size]) {
  // если это буква 'А', то: mas = {0,1,2,0,0,0,0}
  if (mas[0] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(probel);
    }
  else if(mas[0] == 1){
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(probel);
  }
  else return;
   if (mas[1] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(probel);
    }
  else if(mas[1] == 1){
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(probel);
  }
  else return;
   if (mas[2] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(probel);
    }
  else if(mas[2] == 1){
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(probel);
  }
  else return;
  if (mas[3] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(probel);
    }
  else if(mas[3] == 1){
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(probel);
  }
  else return;
}
