// подключаем файл с константами
#include "constant.h"

void setup() {
  Serial.begin(9600);
  pinMode(spiker, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char bykva = Serial.read();
    Serial.println(bykva);
    if (bykva == 'A') {
      speak(azbuka[0]);
    }
    if (bykva == 'B') {
      speak(azbuka[1]);
    }
    if (bykva == 'C') {
      speak(azbuka[2]);
    }
    if (bykva == 'D') {
      speak(azbuka[3]);
    }
    if (bykva == 'E') {
      speak(azbuka[4]);
    }
    if (bykva == 'F') {
      speak(azbuka[5]);
    }
    if (bykva == 'G') {
      speak(azbuka[6]);
    }
    if (bykva == 'H') {
      speak(azbuka[7]);
    }
    if (bykva == 'I') {
      speak(azbuka[8]);
    }
    if (bykva == 'J') {
      speak(azbuka[9]);
    }
    if (bykva == 'K') {
      speak(azbuka[10]);
    }
    if (bykva == 'L') {
      speak(azbuka[11]);
    }
    if (bykva == 'M') {
      speak(azbuka[12]);
    }
    if (bykva == 'N') {
      speak(azbuka[13]);
    }
    if (bykva == 'O') {
      speak(azbuka[14]);
    }
    if (bykva == 'P') {
      speak(azbuka[15]);
    }
    if (bykva == 'Q') {
      speak(azbuka[16]);
    }
    if (bykva == 'R') {
      speak(azbuka[17]);
    }
    if (bykva == 'S') {
      speak(azbuka[18]);
    }
    if (bykva == 'T') {
      speak(azbuka[19]);
    }
    if (bykva == 'U') {
      speak(azbuka[20]);
    }
    if (bykva == 'V') {
      speak(azbuka[21]);
    }
    if (bykva == 'W') {
      speak(azbuka[22]);
    }
    if (bykva == 'X') {
      speak(azbuka[23]);
    }
    if (bykva == 'Y') {
      speak(azbuka[24]);
    }
    if (bykva == 'Z') {
      speak(azbuka[25]);
    
    }
    delay(200);
  
  }
}


void speak(int mas[mas_size]) {
  if (mas[0] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[0] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
    
  }
  else return;

  if (mas[1] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);

  }
  else if (mas[1] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;
  
  if (mas[2] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[2] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;

  if (mas[3] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[3] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;
  if (mas[4] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[4] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;

  if (mas[5] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[5] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;

  if (mas[6] == 0) {
    tone(spiker, sound);
    delay(tochka);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else if (mas[6] == 1) {
    tone(spiker, sound);
    delay(tire);
    noTone(spiker);
    delay(100);
    noTone(spiker);
  }
  else return;
}


// если это буква 'А', то: mas = {0,1,2,0,0,0,0}
