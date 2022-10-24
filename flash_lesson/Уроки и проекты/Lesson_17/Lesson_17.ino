int Voltage;                       //  Создаём переменную типа int для хранения напряжения мотора

void setup(){                      //  Код внутри функции setup выполняется только 1 раз, при старте
    pinMode(7, OUTPUT);            //  Конфигурируем вывод светодиода DV1 как выход
    pinMode(6, OUTPUT);            //  Конфигурируем вывод светодиода DV2 как выход
    pinMode(5, OUTPUT);            //  Конфигурируем вывод светодиода DV3 как выход
    pinMode(4, OUTPUT);            //  Конфигурируем вывод светодиода DV4 как выход
    pinMode(3, OUTPUT);            //  Конфигурируем вывод светодиода DV5 как выход
    pinMode(2, OUTPUT);            //  Конфигурируем вывод светодиода DV6 как выход
}

void loop(){                       //  Код внутри функции loop выполняется постоянно
    Voltage = analogRead(A0);      //  Считываем напряжение с мотора в переменную Voltage
    digitalWrite(7,(Voltage>120)); //  
    digitalWrite(6,(Voltage>100)); //  
    digitalWrite(5,(Voltage>80 )); //  
    digitalWrite(4,(Voltage>60 )); //  
    digitalWrite(3,(Voltage>40 )); //  
    digitalWrite(2,(Voltage>20 )); //  
}
