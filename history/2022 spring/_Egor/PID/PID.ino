#include <Wire.h>               

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

// Serial.println( my_test(3) );

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

double find_e() {
  double e_up = (my_test(1)+2*my_test(2)+3*my_test(3)+4*my_test(4)-my_test(6)-2*my_test(7)-3*my_test(8)-4*my_test(9));
  double e_down = my_test(1)+my_test(2)+my_test(3)+my_test(4)+my_test(5)+my_test(6)+my_test(7)+my_test(8)+my_test(9);
  return e_up/e_down;
}

int my_test(int a) {
  return bum.getLineAnalog(a)>>4;
}

void loop(){ 
  //Serial.println( my_test(3) );

  //int e = my_error(); //int e = bum.getLineAnalog(7) - bum.getLineAnalog(3);

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
  
  int p = e;
  d = d - (e_old-e);
  e_old = e;

  int pid = (p+d)/2;// + d;
  
  Serial.println(e);
  mot_R.setSpeed(70-pid, MOT_PWM);
  mot_L.setSpeed(70+pid, MOT_PWM);

  //find_e();
}
