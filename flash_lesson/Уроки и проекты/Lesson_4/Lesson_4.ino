const int PinKey   = 2;                             //  Константа с № вывода к которому подключёна кнопка
const int PinLed1  = 13;                            //  Константа с № вывода к которому подкл. светодиод 1
const int PinLed2  = 12;                            //  Константа с № вывода к которому подкл. светодиод 2
const int PinLed3  = 11;                            //  Константа с № вывода к которому подкл. светодиод 3
const int PinLed4  = 10;                            //  Константа с № вывода к которому подкл. светодиод 4
      int Timer    = 0;                             //  Переменная для подсчета времени удержания кнопки

void setup(){                                       //  Код внутри функции setup выполняется однократно
    pinMode(PinKey,  INPUT );                       //  Конфигурируем вывод PinKey  как вход
    pinMode(PinLed1, OUTPUT);                       //  Конфигурируем вывод PinLed1 как выход
    pinMode(PinLed2, OUTPUT);                       //  Конфигурируем вывод PinLed2 как выход
    pinMode(PinLed3, OUTPUT);                       //  Конфигурируем вывод PinLed3 как выход
    pinMode(PinLed4, OUTPUT);                       //  Конфигурируем вывод PinLed4 как выход
}
void loop(){                                        //  Код внутри функции loop выполняется постоянно
    if(digitalRead(PinKey)){                        //  Если кнопка нажата (единица на входе PinKey), то ...
        Timer = 0;                                  //  Сбрасываем счетчик времени удержания кнопки
        digitalWrite(PinLed1, 1);                   //  Устанавливаем «1» на выходе PinLed1
        delay(100);                                 //  ждём 100мс, иначе не заметим включение светодиода №1
        digitalWrite(PinLed1, 0);                   //  Устанавливаем «0» на выходе PinLed1
        while(digitalRead(PinKey)){                 //  Выполняем код цикла while пока нажата кнопка
            if(Timer< 11){Timer++;}                 //  Увеличиваем значение Timer на 1, но не более 11 раз
            if(Timer==10){digitalWrite(PinLed3,1);} //  Устанавливаем «1» на выходе PinLed3
            if(Timer> 10){digitalWrite(PinLed4,1);} //  Устанавливаем «1» на выходе PinLed4
            delay(100);                             //  ждём 100мс, иначе не заметим вкл. светодиодов № 3, 4
            if(Timer==10){digitalWrite(PinLed3,0);} //  Устанавливаем «0» на выходе PinLed3
            if(Timer> 10){digitalWrite(PinLed4,0);} //  Устанавливаем «0» на выходе PinLed4
            delay(100);                             //  ждём 100мс, иначе не заметим выкл-ние светодиода № 4
        }
        digitalWrite(PinLed2, 1);                   //  Устанавливаем «1» на выходе PinLed2
        delay(100);                                 //  ждём 100мс, иначе не заметим включение светодиода №2
        digitalWrite(PinLed2, 0);                   //  Устанавливаем «0» на выходе PinLed2
    }
}
