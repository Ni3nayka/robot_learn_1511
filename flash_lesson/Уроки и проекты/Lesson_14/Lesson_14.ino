const int PinVD1 = 12;            //  Константа с № вывода к которому подключён светодиод VD1
const int PinST  = 11;            //  Константа с № входа  к которому подключён датчик вибрация
const int PinVD2 = 10;            //  Константа с № вывода к которому подключён светодиод VD2
bool      Tilt   = 0;             //  Переменная с флагом наклона

void setup(){                     //  Код внутри функции setup выполняется однократно при старте
    pinMode(PinVD1, OUTPUT);      //  Конфигурируем вывод PinVD1 как выход
    pinMode(PinST,  INPUT );      //  Конфигурируем вывод PinST  как вход
    pinMode(PinVD2, OUTPUT);      //  Конфигурируем вывод PinVD2 как выход
}

void loop(){                      //  Код внутри функции loop выполняется постоянно
    Tilt = digitalRead(PinST);    //  Сохраняем состояние входа PinST в переменную Tilt
    digitalWrite(PinVD1,  Tilt);  //  Устанавливаем на выходе PinVD1 состояние     Tilt
    digitalWrite(PinVD2, !Tilt);  //  Устанавливаем на выходе PinVD2 состояние НЕ  Tilt
}
