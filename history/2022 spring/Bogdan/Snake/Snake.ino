// ДАННЫЙ ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ ШИМ: 
                                                  
#include <Wire.h>                                
#include <iarduino_I2C_Motor.h> 
#include <iarduino_I2C_Bumper.h>                  
iarduino_I2C_Motor mot_R(0x0A);                      
iarduino_I2C_Motor mot_L(0x0B); 

#include <iarduino_I2C_Bumper.h> 
iarduino_I2C_Bumper bum(0x0C); 
                                                    
void setup(){                                    
    delay(500); 
    Serial.begin(9600);                                   
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false); 
    
    /*mot_R.setSpeed(  50.0, MOT_PWM);
    mot_L.setSpeed(  50.0, MOT_PWM);                 
    delay(1000);                                 
    mot_R.setSpeed(  0, MOT_PWM);
    mot_L.setSpeed(  0, MOT_PWM);
    delay(1000);
    mot_R.setSpeed(  -100.0, MOT_PWM);
    mot_L.setSpeed(  -100.0, MOT_PWM);
    delay(1000);
    mot_R.setSpeed(  0, MOT_PWM);
    mot_L.setSpeed(  0, MOT_PWM);
    delay(1000);
    mot_R.setSpeed(  100.0, MOT_PWM);
    mot_L.setSpeed(  -100.0, MOT_PWM);
    delay(1000);
    
    mot_R.setSpeed(  -0, MOT_PWM);
    mot_L.setSpeed(  0, MOT_PWM);
    delay(1000);*/
    
    
      
 }
void loop(){                                    
    Serial.println(bum.getLineAnalog(3));
    int d_r = bum.getLineAnalog(7)>1000;
    int d_l = bum.getLineAnalog(3)>1000;
    
    if (d_r && d_l || !d_r && !d_l) {
     mot_R.setSpeed(  100, MOT_PWM);
     mot_L.setSpeed(  100, MOT_PWM);
    }
    else if(!d_r && d_l) {
     mot_R.setSpeed(  -100, MOT_PWM);
     mot_L.setSpeed(  100, MOT_PWM);
    }
    else if(d_r && !d_l) {
     mot_R.setSpeed(  100, MOT_PWM);
     mot_L.setSpeed(  -100, MOT_PWM);
    }
    else {
     mot_R.setSpeed(  100, MOT_PWM);
     mot_L.setSpeed(  100, MOT_PWM);
    }
}
