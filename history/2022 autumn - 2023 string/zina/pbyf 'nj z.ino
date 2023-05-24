#include <Wire.h>
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0A);
iarduino_I2C_Motor mot_R(0x0B);
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
int motor_sped = 100;
int M = 100;
#define PIN_TRIG 4
#define PIN_ECHO 5
long duration, cm;

void setup() {
  delay(500);
  mot_L.begin();
  mot_R.begin();
  mot_R.setDirection(true);
  mot_L.setDirection(false);
  Serial.begin(9600);
  bum.begin();
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

}
int l = 0 ;
int e_jkl = 0;
int b = 0;
void loop() {

hfcnjzybt();   
int e = cm-50;
  //int e = bum.getLineAnalog (8) - bum.getLineAnalog (2) ;
    int P = e * 0.7;
    b = (b + e) * 0.02;

    motor (M - P, M + P);

    l = l + (e - e_jkl) * 0.06;
    e_jkl = e;
    int gbl = P;


  /*  Serial.println (bum.getLineAnalog(1));
     if (bum.getLineAnalog (2) > 1500 && bum.getLineAnalog (8) > 1500 )
     {
       motor (100, 100) ;
     }
     else if (bum.getLineAnalog (2) < 1500 && bum.getLineAnalog (8) > 1500) {
       motor (0, 100);
     }

     else if (bum.getLineAnalog (8) < 1500 && bum.getLineAnalog (2) > 1500) {
       motor (100, 0);
     }

       else if (bum.getLineAnalog (8) < 1500 && bum.getLineAnalog (2) < 1500) {
       motor (100, 10
       0);

     }*/
  /*  if (Serial.available() > 0) {
      char f = Serial.read();
      if (nhteujkmybr ==0){
      if (f == 'F') motor(motor_sped, motor_sped);
      if (f == 'S') motor(0, 0);
      if (f == 'B') motor(-motor_sped, -motor_sped);
      if (f == 'L') motor(-motor_sped, motor_sped);
      if (f == 'R') motor(motor_sped, -motor_sped);
      if (f == 'G') motor(motor_sped/2, motor_sped);
      if (f == 'I') motor(motor_sped, motor_sped/2);
      if (f == 'H') motor(-motor_sped/2, -motor_sped);
      if (f == 'J') motor(-motor_sped, -motor_sped/2);
      if (f == '0') motor_sped = 0;
      if (f == '1') motor_sped =10;
      if (f == '2') motor_sped =20;
      if (f == '3') motor_sped =30;
      if (f == '4') motor_sped =40;
      if (f == '5') motor_sped =50;
      if (f == '6') motor_sped =60;
      if (f == '7') motor_sped =70;
      if (f == '8') motor_sped =80;
      if (f == '9') motor_sped =90;
      if (f == 'q') motor_sped=100;}
      if (f=='X') nhteujkmybr=1;
      if (f=='x') nhteujkmybr=0 ;
    }*/
}
void motor(int l, int r) {
  mot_L.setSpeed( l, MOT_PWM);
  mot_R.setSpeed( r, MOT_PWM);
}
/*void sped (int sped1, int sped2) {
  mot_L.  (sped1);
  mot_R.  (sped2);

  }*/
void hfcnjzybt () {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);


  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  
  duration = pulseIn(PIN_ECHO, HIGH);

 
  cm = (duration / 2) / 29.1;

  //Serial.print("Расстояние до объекта: ");
//  Serial.print(cm);
  //Serial.println(" см.");



}
