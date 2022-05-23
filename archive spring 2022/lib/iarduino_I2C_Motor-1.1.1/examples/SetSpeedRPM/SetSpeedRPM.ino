// ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ СКОРОСТИ:   // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor mot(0x09);                     //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    mot.begin();                                  //   Инициируем работу с мотором.
}                                                 //
                                                  //
void loop(){                                      //
    mot.setSpeed(  60, MOT_RPM);                  //   Запускаем мотор на скорости   60 об/мин, что соответствует 1 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( 120, MOT_RPM);                  //   Запускаем мотор на скорости  120 об/мин, что соответствует 2 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(  60, MOT_RPM);                  //   Запускаем мотор на скорости   60 об/мин, что соответствует 1 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(   0, MOT_RPM);                  //   Запускаем мотор на скорости    0 об/мин, что соответствует остановке мотора.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -60, MOT_RPM);                  //   Запускаем мотор на скорости  -60 об/мин, что соответствует -1 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(-120, MOT_RPM);                  //   Запускаем мотор на скорости -120 об/мин, что соответствует -2 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -60, MOT_RPM);                  //   Запускаем мотор на скорости  -60 об/мин, что соответствует -1 об/сек.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(   0, MOT_RPM);                  //   Запускаем мотор на скорости    0 об/мин, что соответствует остановке мотора.
    delay(5000);                                  //   Приостанавливаем выполнение скетча на 5 секунд.
}                                                 //
