#include <Wire.h>                                          // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Bumper.h>                           //   Подключаем библиотеку для работы с бампером I2C-flash.
iarduino_I2C_Bumper bum(0x0A); 

#include <iarduino_I2C_IR.h>
iarduino_I2C_IR ir(0x0B);

#include <Servo.h>
Servo myservo;

#define DIR_pin 4
#define PWM_pin 5

void setup() {
  Serial.begin(9600);
  pinMode(DIR_pin,OUTPUT);
  pinMode(PWM_pin,OUTPUT);
  myservo.attach(3);
  bum.begin(); 
  ir.begin();
  ir.setProtocol(IR_IARDUINO);

  /*motor(100);
  delay(2000);
  motor(30);
  delay(2000);
  motor(0);*/

  /*turn(0);
  delay(1000);
  turn(40);  
  delay(1000);
  turn(-40);  */

  
  //obiezd();

/*
  for (int i = -40; i<=40; i++) {
    turn(i);
    delay(50);
  }
  delay(500)
;  while (1) turn(0);*/
  
  //while (1) PID_test();
  //turn_left();
  motor(0);
  //while (1);
  
  
  
}

bool flag = 1;
int max_speed = 100;
float old_summ = 0;
bool obiezd_flag = 0;


void loop() {
  if (ir.check(true)) {
    if (ir.device==MODUL_TLIGHT) {
      flag = ir.forvard;
    }
    else if (ir.device==MODUL_SIGN) {
      if (!strcmp(ir.sign_str,"1.12.1")) max_speed = 30;
      else if (!strcmp(ir.sign_str,"3.31")) max_speed = 100;
      else if (!strcmp(ir.sign_str,"4.2.2")) obiezd();
      else if (!strcmp(ir.sign_str,"3.1")) flag = 0;
    }
  }

  if (summa_dat()<4000 && obiezd_flag) turn_left();
  
  PID();
  //Serial.println(summa_dat());
}

void turn_left() {
  motor(100);
  turn(-40);
  bum.setTurnSignal(BUM_TURN_LEFT);
  delay(2000);
  while (summa_dat()>4900);
  bum.setTurnSignal(BUM_TURN_OFF);
  obiezd_flag = 0;
}

int summa_dat() {
  int a = 0;
  for (int i = 1; i<=9; i++) 
    a += bum.getLineAnalog(i)>>2;
  Serial.println(a);
  return a;
}

void obiezd() {
  bum.setTurnSignal(BUM_TURN_LEFT);
  motor(100);
  turn(-40);
  delay(2000);
  bum.setTurnSignal(BUM_TURN_OFF);
  bum.setTurnSignal(BUM_TURN_RIGHT);
  turn(40);
  delay(4000);
  
  //while (bum.getLineAnalog(7)>1000);
  bum.setTurnSignal(BUM_TURN_OFF);
  bum.setTurnSignal(BUM_TURN_EMERGENCY);
  turn(0);
  //while (bum.getLineAnalog(9)>500 && bum.getLineAnalog(1)>500);
  while (summa_dat()>4900);
  bum.setTurnSignal(BUM_TURN_OFF);
  obiezd_flag = 1;
}

void PID() {
  if (!flag) {
    motor(0);
    return;
  }
  //int a = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  //a /= 50;
  float a = bum.getErrPID();
  /*float a = 0;
  if (summa_dat()<4900) {
    a = bum.getErrPID();
  }
  else a = old_summ;
  old_summ = a>0?4,5:-4,5;*/
  turn(a*10);
  motor(max_speed);
}

void PID_test() {
  int a = bum.getErrPID();
  //Serial.println(a);
  turn(a*9);
  motor(max_speed);
}

void turn(int pos) {
  //myservo.write(map(constrain(pos,-40,40),-40,40,50,130)); 
  myservo.write(constrain(pos,-40,40)+102); 
}

void motor(int speed) {
  digitalWrite(DIR_pin,speed>0);
  analogWrite(PWM_pin,map(constrain(abs(speed),0,100),0,100,0,255));
}
