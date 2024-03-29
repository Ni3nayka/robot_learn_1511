const int PinRes = A5;                   //  Константа с № входа  к которому подключён фоторезистор
const int PinLed = 9;                    //  Константа с № вывода к которому подключён светодиод
      int ValRes = 0;                    //  Переменная для хранения прочитанного напряжения    (0...1023)
      int ValPWM = 0;                    //  Переменная для хранения рассчитанного значения ШИМ (0... 255)

void setup(){                            //  Код внутри функции setup выполняется однократно при старте
    pinMode(PinLed, OUTPUT);             //  Конфигурируем вывод, с ШИМ, PinLed как выход
}                                        //  Аналоговые входы можно не конфигурировать!

void loop(){                             //  Код внутри функции loop выполняется постоянно
    ValRes = analogRead(PinRes);         //  Считываем напряжение с аналогового входа PinRes
    ValPWM = map(ValRes, 200,1024, 0,255); //  Преобразуем ValRes (от 0 до 1023) к ValPWM (от 0 до 255)
    analogWrite(PinLed, ValPWM);         //  Устанавливаем ШИМ с коэффициентом ValPWM на выходе PinLed
}
