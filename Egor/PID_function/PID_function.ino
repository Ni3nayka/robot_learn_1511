#include <Wire.h>     

#define Kp  2
#define Kd  1

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

long int d = 0;
int e_old = 0;
                                                 
void setup(){       
    delay(500); 
    Serial.begin(9600);
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false);
    
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);

    
    
    
}

int test_datchik() {
  int e = 0;
  if (bum.getLineAnalog(1)<1000) e -= 32;
  if (bum.getLineAnalog(2)<1000) e -= 16;
  if (bum.getLineAnalog(3)<1000) e -= 8;
  if (bum.getLineAnalog(4)<1000) e -= 4;
  //if (bum.getLineAnalog(0)<1000) e -= 0;
  if (bum.getLineAnalog(6)<1000) e += 4;
  if (bum.getLineAnalog(7)<1000) e += 8;
  if (bum.getLineAnalog(8)<1000) e += 16;
  if (bum.getLineAnalog(9)<1000) e += 32;
  return e;
}

int operating_pid(int e) {
  int p = e*Kp;
  d = d - (e-e_old)*Kd;
  e_old = e;
  int pid = (p+d)/2;
  return pid;
}

void forward() {
  if (bum.getLineAnalog(1)<1000 && bum.getLineAnalog(9)>1000) {
    motor(-40);
  }
  else if (bum.getLineAnalog(1)>1000 && bum.getLineAnalog(9)<1000) {
    motor(40);
  }
  else {
    motor(0);
  }
}

void ostanovka()  {
  mot_R.setSpeed(0, MOT_PWM);
  mot_L.setSpeed(0, MOT_PWM);
}

void loop(){ 
  /*unsigned long int t = millis();
  //Serial.println(t);
  if (t>3000) {
    Serial.println("!");
  }
  else {
    
  }*/
  int e = test_datchik();
  int pid1 = operating_pid(e);
  //Serial.println(e);
  motor(pid1);
  //int e = test_datchik();
  //motor(e);
  
}

void motor(int a) {
  mot_R.setSpeed(70-a, MOT_PWM);
  mot_L.setSpeed(70+a, MOT_PWM);
}
