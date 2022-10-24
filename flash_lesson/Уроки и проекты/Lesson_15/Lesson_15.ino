const int PinHall = A1;                   //  Константа с № аналогового входа к которому подключён Датчик
const int PinLedR = 12;                   //  Константа с № вывода к которому подключён светодиод R
const int PinLedG = 11;                   //  Константа с № вывода к которому подключён светодиод G
const int PinLedB = 10;                   //  Константа с № вывода к которому подключён светодиод B
      int ValHall = 0;                    //  Переменная для хранения данных с датчика (0...1023)
      int ValLED  = 0;                    //  Переменная указывающая какой светодиод включить (-1, 0, +1)

void setup(){                             //  Код внутри функции setup выполняется однократно при старте
    pinMode(PinLedR, OUTPUT);             //  Конфигурируем вывод, PinLedR как выход
    pinMode(PinLedG, OUTPUT);             //  Конфигурируем вывод, PinLedR как выход
    pinMode(PinLedB, OUTPUT);             //  Конфигурируем вывод, PinLedR как выход
}                                         //  Аналоговый вход PinHall можно не конфигурировать!

void loop(){                              //  Код внутри функции loop выполняется постоянно
    ValHall = analogRead(PinHall);        //  Считываем напряжение с аналогового входа PinHall
    ValLED  = 0;                          //  Обнуляем переменную ValLED
    if(ValHall<(511-10)){ValLED=-1;}      //  Присваиваем ValLED значение -1, если ValHall < 512-10
    if(ValHall>(511+10)){ValLED=+1;}      //  Присваиваем ValLED значение +1, если ValHall > 512+10
    digitalWrite(PinLedR,!(ValLED==-1));  //  Включаем красный светодиод, если ValLED равно -1
    digitalWrite(PinLedG,!(ValLED== 0));  //  Включаем зелёный светодиод, если ValLED равно  0
    digitalWrite(PinLedB,!(ValLED== 1));  //  Включаем синий   светодиод, если ValLED равно +1
}
