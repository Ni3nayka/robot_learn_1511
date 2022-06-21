// подключаем файл с константами
#include "constant.h"

void setup() {
  Serial.begin(9600);
  pinMode (spiker, OUTPUT);
}


void loop() {
  if (Serial.available()) {
    char bykva = Serial.read();
    if (bykva == 'A') speak(azbuka[0]);
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'C') speak(azbuka[2])
    if bykva == 'D') speak(azbuka[1])
    if bykva == 'E') speak(azbuka[1])
    if bykva == 'F') speak(azbuka[1])
    if bykva == 'G') speak(azbuka[1])
    if bykva == 'H') speak(azbuka[1])
    if bykva == 'I') speak(azbuka[1])
    if bykva == 'J') speak(azbuka[1])
    if bykva == 'K') speak(azbuka[1])
    if bykva == 'L') speak(azbuka[1])
    if bykva == 'M') speak(azbuka[1])
    if bykva == 'N') speak(azbuka[1])
    if bykva == 'O') speak(azbuka[1])
    if bykva == 'P') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1])
    if bykva == 'B') speak(azbuka[1]) 
    };

}

void speak(int mas[mas_size]) {
  // если это буква 'А', то: mas = {0,1,2,0,0,0,0}
  if (mas[0] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[0] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
if (mas[1] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[1] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
  if (mas[2] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[2] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
  if (mas[3] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[3] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
  if (mas[4] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[4] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
  if (mas[5] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[5] == 1) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;
  if (mas[6] == 0) {
    tone(spiker, 1000);
    delay(600);
    noTone(spiker);
    delay (600);
  }
  else if (mas[6] == 1) {
    tone(spiker,1000);
    delay(600);
    noTone(spiker);
    delay(600);
    
  }
  else return;}
