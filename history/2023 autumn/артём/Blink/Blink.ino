#include "qwerty.h"



void setup ()

{
setup_motor ();
}

void loop() {
  

  motor_ab(255 , 255 , 1000);
  motor_ab(0 , 0 , 1000);
  motor_ab(-255 , -255 , 1000);
  motor_ab();

}







