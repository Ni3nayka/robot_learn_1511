#include <Wire.h>

#define Kp   2
#define Kd   1

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

// Serial.println( bum.getLineAnalog(3) );

long int d=0;
int e_old = 0;

void setup(){       
    delay(500); 
    Serial.begin(9600);
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false);
     
    /*mot_R.setSpeed(100, MOT_PWM);
    mot_L.setSpeed(100, MOT_PWM);
    delay(1000);
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);
    delay(1000);
    mot_R.setSpeed(-100, MOT_PWM);
    mot_L.setSpeed(-100, MOT_PWM);
    delay(1000);*/
    
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);
    
}

int find_e() {
  double e_up = (bum.getLineAnalog(1)+2*bum.getLineAnalog(2)+3*bum.getLineAnalog(3)+4*bum.getLineAnalog(4))-(bum.getLineAnalog(9)+2*bum.getLineAnalog(8)+3*bum.getLineAnalog(7)+4*bum.getLineAnalog(6));
  double e_down = bum.getLineAnalog(1)+bum.getLineAnalog(2)+bum.getLineAnalog(3)+bum.getLineAnalog(4)+bum.getLineAnalog(5)+bum.getLineAnalog(6)+bum.getLineAnalog(7)+bum.getLineAnalog(8)+bum.getLineAnalog(9);
  return e_up/e_down;
}

int test_datchik() {
  int e=0;
  if (bum.getLineAnalog(1)<1000) e-=32;
  if (bum.getLineAnalog(2)<1000) e-=16;
  if (bum.getLineAnalog(3)<1000) e+=8;
  if (bum.getLineAnalog(4)<1000) e+=4;
  //if (bum.getLineAnalog(5)<1000) e+=0;
  if (bum.getLineAnalog(6)<1000) e+=4;
  if (bum.getLineAnalog(7)<1000) e+=8;
  if (bum.getLineAnalog(8)<1000) e+=16;
  if (bum.getLineAnalog(9)<1000) e+=32;
  return e;
}

int operating_pid(int e) {
  int p = e*Kd;
  d = d - (e_old-e);
  e_old = e;
  int pid = (p+d)/Kp;
  return pid;
}
  

void loop(){ 
  unsigned long int t = millis();
  if (t>10000) {
    povorot_motorov();
    mot_R.setSpeed(0, MOT_PWM);
    mot_L.setSpeed(0, MOT_PWM);
  }
  else {
    forward();
  }
}
void motor(int a) {
  mot_R.setSpeed(50-a, MOT_PWM);
  mot_L.setSpeed(50+a, MOT_PWM);
}

void povorot_motorov() {
  unsigned long int t = millis();
  mot_R.setSpeed(0, MOT_PWM);
  mot_L.setSpeed(0, MOT_PWM);
  delay(1000);
  mot_R.setSpeed(50, MOT_PWM);
  mot_L.setSpeed(-50, MOT_PWM);
  delay(1500);
  mot_R.setSpeed(0, MOT_PWM);
  mot_L.setSpeed(0, MOT_PWM);
  delay(1000);
  t=millis();
  while(millis()-t<10000){
    forward();
  }
}
void forward() {
  int e = test_datchik();
  int pid = operating_pid(e);
  motor(pid);
}
