#include <Servo.h>                  //  Подключаем библиотеку Servo

const int PinRes = A0;              //  Создаём константу с № входа к которому подключен потенциометр
const int PinSer = 12;              //  Создаём константу с № вывода к которому подключен сервопривод
int       Angle;                    //  Создаём переменную типа int для хранения угла поворота в градусах
Servo     ObjSer;                   //  Создаём объект для работы с библиотекой Servo

void setup(){                       //  Код внутри функции setup выполняется только 1 раз, при старте
    ObjSer.attach(PinSer);          //  Вызываем функцию attach объекта ObjSer с параметром PinSer, указывая
}                                   //  библиотеке, что сервопривод подключён к выводу PinSer

void loop(){                        //  Код внутри функции loop выполняется постоянно
    Angle = analogRead(PinRes);     //  Считываем состояние со входа PinRes в переменную Angle
    Angle = map(Angle,0,1023,0,180);//  Преобразуем значение переменной Angle в градусы ( 0° ... 180° )
    ObjSer.write(Angle);            //  Вызываем функцию write объекта ObjSer с параметром Angle, указывая
}                                   //  библиотеке, что сервопривод нужно повернуть на угол Angle
