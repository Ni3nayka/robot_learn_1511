#include <Wire.h> 
#include <iarduino_I2C_Bumper.h>                          
iarduino_I2C_Bumper bum(0x0C);                                  
#include <iarduino_I2C_Motor.h>                  
iarduino_I2C_Motor mot(0x0A);                  
iarduino_I2C_Motor motor(0x0B);
const int beliy = 1500;
const int Prosto_skorost = 80;
void setup() {
  Serial.begin(9600);
  delay(500);
  motor.begin();
  mot.begin();
  mot.setDirection(true);                      
  motor.setDirection(false); 
  delay(500);                                           
  Serial.begin(9600);                                      
  bum.begin();

}
int I = 0;
void loop() {
  int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  int p_reg = err;
  I = I + err;
  int PID = p_reg*0.017 + I*0.002;
  ben(Prosto_skorost+PID,Prosto_skorost-PID);
}




void ben(int l, int r) {
  mot.setSpeed(r, MOT_PWM);                
     
  motor.setSpeed(l, MOT_PWM);
           
                                     
}
