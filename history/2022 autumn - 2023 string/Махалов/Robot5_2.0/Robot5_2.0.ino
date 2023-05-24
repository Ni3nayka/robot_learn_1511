#include <Wire.h> 
#include <iarduino_I2C_Bumper.h>                          
iarduino_I2C_Bumper bum(0x0C);                                  
#include <iarduino_I2C_Motor.h>                  
iarduino_I2C_Motor mot(0x0A);                  
iarduino_I2C_Motor motor(0x0B);
const int beliy = 1500;
const int skorost = 80;
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

void loop() {
  int err = bum.getLineAnalog(3) - bum.getLineAnalog(7);
  if (getLineAnalog(3)>getLineAnalog(7) ben(-50, 75));
  else if (getLineAnalog(7)>getLineAnalog(3) ben(75, -50));
  else ben(80, 80);
}




void ben(int l, int r) {
  mot.setSpeed(r, MOT_PWM);                
     
  motor.setSpeed(l, MOT_PWM);
           
                                     
}
