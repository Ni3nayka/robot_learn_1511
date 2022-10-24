const int PinKey = 2;              // Создаём константу с номером вывода к которому подключена кнопка
const int PinVT  = 12;             // Создаём константу с номером вывода к которому подключены транзисторы
bool      Action = 0;              //  Создаём переменную типа bool для хранения состояния кнопки (1-нажата / 0-отпущена)

void setup(){                      //  Код внутри функции setup выполняется только 1 раз, при старте
    pinMode(PinKey, INPUT);        //  Конфигурируем вывод PinKey как вход
    pinMode(PinVT, OUTPUT);        //  Конфигурируем вывод PinVT как выход
}

void loop(){                       //  Код внутри функции loop выполняется постоянно
    Action = digitalRead(PinKey);  //  Считываем состояние со входа PinKey в Action
    digitalWrite(PinVT, Action);   //  Устанавливаем состояние Action на выходе PinVT
}
