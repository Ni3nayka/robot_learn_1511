#include <Servo.h>

// создаём объекты для управления сервоприводами
Servo myservo1;
 
void setup() 
{
  // подключаем сервоприводы к выводам 11 и 12
  myservo1.attach(9);
} 
 
void loop() 
{
  // устанавливаем сервоприводы в серединное положение
  myservo1.write(90);
  delay(500);
  // устанавливаем сервоприводы в крайнее левое положение  
  myservo1.write(0);
  delay(500);
  // устанавливаем сервоприводы в крайнее правое положение
  myservo1.write(180);
  delay(500);
}