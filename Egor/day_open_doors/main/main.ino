// https://robotraffik.ru/

#include <iarduino_I2C_Motor.h> 
iarduino_I2C_Motor mot_L(0x0A);
iarduino_I2C_Motor mot_R(0x0B);

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C); 

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11, 12); // RX, TX

int mode = 1;
int speed = 10;

void setup() {
  delay(500);
  bluetooth.begin(9600);
  
  Serial.begin(9600);             //  Настраиваем COM-порт на работу со скоростью 9600 бит/сек
  Serial.println("Setup:");
  Serial.print("supply voltage: "); Serial.println(voltmetr());
  Serial.print("mot_L: "); serial_test(mot_L.begin());
  Serial.print("mot_R: "); serial_test(mot_R.begin());
  Serial.print("bumper: "); serial_test(bum.begin());
  Serial.println("Setup - end");

  mot_L.setDirection(false);  //   Задаём направление вращения для левого  мотора: против часовой стрелки при положительных скоростях и по при отрицательных.                  
  mot_R.setDirection(true ); 
  
  /*mot_L.setSpeed( 50, MOT_PWM);
  mot_R.setSpeed( 50, MOT_PWM);
  delay(2000);
  mot_L.setStop();
  mot_R.setStop();  */

}
void loop() {
  //Serial.println(voltmetr()); //  Выводим в порт считанные с аналогового пина данные
  //Serial.println(bum.getLineAnalog(5));

  if (bluetooth.available()) {
    char input = bluetooth.read();
    //Serial.println(input);
    if      (input=='X') mode = 2;
    else if (input=='x') mode = 1;
    else if (input=='S' && mode==1) motors(0,0);
    else if (input=='F' && mode==1) motors(speed,speed);
    else if (input=='B' && mode==1) motors(-speed,-speed);
    else if (input=='L' && mode==1) motors(-speed,speed);
    else if (input=='R' && mode==1) motors(speed,-speed);
    else if (input=='q') speed = 10;
    else if (input=='9') speed = 9;
    else if (input=='8') speed = 8;
    else if (input=='7') speed = 7;
    else if (input=='6') speed = 6;
    else if (input=='5') speed = 5;
    else if (input=='4') speed = 4;
    else if (input=='3') speed = 3;
    else if (input=='2') speed = 2;
    else if (input=='1') speed = 1;
    else if (input=='0') speed = 0;
    //else if (input=='') speed = ;
  }
  if (mode==2) {
    //motors(0,0);
    //for (int i = 1; i<=9; i++) Serial.print(String(bum.getLineAnalog(i))+String(" ")); Serial.println();
    //double K = 0.05;
    int e = bum.getLineAnalog(3)-bum.getLineAnalog(7);
    motors(60+e*0.03,60-e*0.03);
    //Serial.println(60+e*0.03);
  }
}

void motors(int a, int b) {
  mot_L.setSpeed( a*10, MOT_PWM);
  mot_R.setSpeed( b*10, MOT_PWM);
}

void serial_test(bool test) {
  if (test) Serial.println("OK"); else Serial.println("ERROR");
}
float voltmetr() { return analogRead(A0)/64.4; }
