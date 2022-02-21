#include <Wire.h>               

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

// Serial.println( bum.getLineAnalog(3) );
 long int d = 0;
 int e_old = 0;                                             
void setup()
{       
    delay(500); 
    Serial.begin(9600);
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(false);
    mot_L.setDirection(true);
     
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

void loop()
{ 

  int e = 0;
  if (bum.getLineAnalog(1)<1000) e -= 32;
  if (bum.getLineAnalog(2)<1000) e -= 16;
  if (bum.getLineAnalog(3)<1000) e -= 8;
  if (bum.getLineAnalog(4)<1000) e -= 4;
  if (bum.getLineAnalog(6)<1000) e += 4;
  if (bum.getLineAnalog(7)<1000) e += 8;
  if (bum.getLineAnalog(8)<1000) e += 16;
  if (bum.getLineAnalog(9)<1000) e += 32;
  int p = e;
  d = d - (e_old-e)/25;
  e_old = e;
  int pid = p;
  mot_R.setSpeed(70+pid, MOT_PWM);
  mot_L.setSpeed(70-pid, MOT_PWM);
}
