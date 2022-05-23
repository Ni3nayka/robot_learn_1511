#include <Wire.h>  

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(11, 12);

#define BTH bluetooth

 long int d = 0;
 int e_old = 0;
 int M = 25;
 
void setup()
{       
    delay(500);
    Serial.begin(9600);
    bluetooth.begin(9600);
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(false);
    mot_L.setDirection(true);
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);
}

void loop()
{ 
  if(BTH.available())
  {
    char t = BTH.read();
    {
      if (t =='S')
      {
        mot_R.setSpeed( 0, MOT_PWM);
        mot_L.setSpeed( 0, MOT_PWM);
      }
      else if (t =='F')
      {
        mot_R.setSpeed( M, MOT_PWM);
        mot_L.setSpeed( M, MOT_PWM);
      }
      else if (t =='B')
      {
        mot_R.setSpeed( -M, MOT_PWM);
        mot_L.setSpeed( -M, MOT_PWM);
      }
      else if (t =='R')
      {
        mot_R.setSpeed( M, MOT_PWM);
        mot_L.setSpeed( -M, MOT_PWM);
      }
      else if (t =='L')
      {
        mot_R.setSpeed( -M, MOT_PWM);
        mot_L.setSpeed( M, MOT_PWM);
      }
      else if (t =='I')
      {
        mot_R.setSpeed( M, MOT_PWM);
        mot_L.setSpeed( M/2, MOT_PWM);
      }
       else if (t =='G')
      {
        mot_R.setSpeed( M/2, MOT_PWM);
        mot_L.setSpeed( M, MOT_PWM);
      }
      else if (t =='H')
      {
        mot_R.setSpeed( -M, MOT_PWM);
        mot_L.setSpeed( -M/2, MOT_PWM);
      }
      else if (t =='J')
      {
        mot_R.setSpeed( -M/2, MOT_PWM);
        mot_L.setSpeed( -M, MOT_PWM);
      }
      else if (t =='0') M = 0;
      else if (t =='1') M = 10;
      else if (t =='2') M = 20;
      else if (t =='3') M = 30;
      else if (t =='4') M = 40;
      else if (t =='5') M = 50;
      else if (t =='6') M = 60;
      else if (t =='7') M = 70;
      else if (t =='8') M = 80;
      else if (t =='9') M = 90;
      else if (t =='q') M = 100;
    }
  }
}

/*void motor(int a)
{
  mot_R.setSpeed(70+a, MOT_PWM);
  mot_L.setSpeed(70-a, MOT_PWM);
}

int dathic()
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
  return e;
}

int operating_pid(int e)
{
  int p = e*Kp;
  d = d - (e_old-e)/25*Kd;
  e_old = e;
  int pid = (p+d)/2;
  return pid;
}
int ostanovka()
{
  mot_R.setSpeed( 0, MOT_PWM);
  mot_L.setSpeed( 0, MOT_PWM);
}*/
