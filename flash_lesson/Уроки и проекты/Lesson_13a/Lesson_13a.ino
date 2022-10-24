const int PinSV = 2;                          //  Константа с № входа  к которому подключён датчик вибраций
const int PinVD = 9;                          //  Константа с № вывода к которому подключён светодиод

void setup(){                                 //  Код внутри функции setup выполняется однократно при старте
    pinMode(PinSV, INPUT);                    //  Конфигурируем вывод PinSV как вход
    pinMode(PinVD, OUTPUT);                   //  Конфигурируем вывод PinVD как выход
}

void loop(){                                  //  Код внутри функции loop выполняется постоянно
    digitalWrite(PinVD, digitalRead(PinSV));  //  Копируем состояние входа PinSV на выход PinVD
}
