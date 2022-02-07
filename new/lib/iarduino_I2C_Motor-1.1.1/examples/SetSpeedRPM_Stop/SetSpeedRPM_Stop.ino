// ПРИМЕР ЗАПУСКАЕТ МОТОР С УСЛОВИЕМ ОСТАНОВКИ:   // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor mot(0x09);                     //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    mot.begin();                                  //   Инициируем работу с мотором.
    mot.radius = 12.2;                            //   Указываем радиус колеса в мм.
}                                                 //
                                                  //
void loop(){                                      //
    mot.setSpeed(60, MOT_RPM, 0.1, MOT_MET);      //   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 0.1 метра.
    delay(10000);                                 //   Приостанавливаем выполнение скетча на 10 секунд.
    mot.setSpeed(60, MOT_RPM,   3, MOT_REV);      //   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 3 полных оборота.
    delay(10000);                                 //   Приостанавливаем выполнение скетча на 10 секунд.
    mot.setSpeed(60, MOT_RPM,   2, MOT_SEC);      //   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 2 секунды.
    delay(10000);                                 //   Приостанавливаем выполнение скетча на 10 секунд.
}                                                 //
