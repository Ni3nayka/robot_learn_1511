// Пример получения и указания типа линии трассы:          // * Строки со звёздочкой являются необязательными.
                                                           //
#include <Wire.h>                                          // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Bumper.h>                           //   Подключаем библиотеку для работы с бампером I2C-flash.
iarduino_I2C_Bumper bum(0x09);                             //   Объявляем объект bum для работы с функциями и методами библиотеки iarduino_I2C_Bumper, указывая адрес модуля на шине I2C.
                                                           //   Если объявить объект без указания адреса (iarduino_I2C_Bumper bum;), то адрес будет найден автоматически.
void setup(){                                              //
    delay(500);                                            // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                                    //   Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
    while(!Serial){;}                                      // * Ждём завершения инициализации шины UART.
    bum.begin();                                           //   Инициируем работу с бампером.
}                                                          //
                                                           //
void loop(){                                               //
//  ВЫВОДИМ ИСПОЛЬЗУЕМЫЙ ТИП ЛИНИИ:                        //
    Serial.print("Модуль использовал трассу с ");          //
    switch(bum.getLineType()){                             //   Получаем используемый модулем тип линии.
      case BUM_LINE_BLACK: Serial.print("тёмной" ); break; //
      case BUM_LINE_WHITE: Serial.print("светлой"); break; //
      default:             Serial.print("неизвестной");    // * 
    }                      Serial.print(" линией, ");      //
//  УКАЗЫВАЕМ НОВЫЙ ТИП ЛИНИИ:                             //
    bum.setLineType(BUM_LINE_CHANGE);                      //   Тип линии задаётся как BUM_LINE_BLACK - тёмная / BUM_LINE_WHITE - светлая / BUM_LINE_CHANGE - сменить тип линии.
//  ВЫВОДИМ ИСПОЛЬЗУЕМЫЙ ТИП ЛИНИИ:                        //
    Serial.print("а теперь использует трассу с ");         //
    switch(bum.getLineType()){                             //   Получаем используемый модулем тип линии.
      case BUM_LINE_BLACK: Serial.print("тёмной" ); break; //
      case BUM_LINE_WHITE: Serial.print("светлой"); break; //
      default:             Serial.print("неизвестной");    // * 
    }                      Serial.print(" линией.\r\n");   //
//  добавляем задержку:                                    //
    delay(2000);                                           //
}                                                          //
                                                           //
/* Тип линии, равно как и калибровочные значения,          //
 * хранятся в энергонезависимой памяти модуля.             //
 * Значит тип линии сохранится и после отключения питания. //
 */                                                        //