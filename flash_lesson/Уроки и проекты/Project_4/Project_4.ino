const uint8_t PinLED[ 3] = {13,11,9}; //  Создаём массив констант с № выходов к которым подключены светодиоды
const uint8_t PinKEY[ 3] = {12,10,8}; //  Создаём массив констант с № входов  к которым подключены кнопки
      uint8_t Task[99];               //  Создаём массив заданий (последовательность цветов)
      uint8_t Level      = 0;         //  Создаём переменную для хранения № текущего уровня
      uint8_t NumKey     = 0;         //  Создаём переменную для хранения № нажатой клавиши
      uint8_t SumKey     = 0;         //  Создаём переменную для подсчёта количества нажатий клавиш
      bool    Start      = 1;         //  Создаём флаг старта

void setup(){
    for(int i=0; i<3; i++){           //  Конфигурируем выводы и выключаем светодиоды
        pinMode(PinLED[i],OUTPUT); digitalWrite(PinLED[i],HIGH); pinMode(PinKEY[i],INPUT);
    }   randomSeed(analogRead(0));    //  Назначаем случайное число со входа A0, для генератора random()
}

void loop(){
    NumKey=3; for(int i=0; i<3; i++){if(digitalRead(PinKEY[i])){NumKey=i; SumKey++;}} // фиксируем нажатие
    if(NumKey<3){                                          //  Если зафиксировано нажатие кнопки, то ...
              digitalWrite(PinLED[NumKey],0);              //  Включаем светодиод над кнопкой
        while(digitalRead (PinKEY[NumKey]  )){delay(50);}  //  Ждем, пока не отпустят кнопку
              digitalWrite(PinLED[NumKey],1);              //  Выключаем светодиод над кнопкой
        if(Task[SumKey-1]!=NumKey){Level=0; Start=1;}      //  Если ошибка, то переходим на 0 уровень
        if(!Start && SumKey>Level){Level++; Start=1;}      //  Если нет ошибок, то увеличиваем уровень
    }
    if(Start){                                             //  Если начат новый уровень, то ...
        Start=SumKey=0; Task[Level]=random(0,3);           //  Придумываем последний цвет от 0 до 2
        if(Level==0){                                      //  Если начат 0 уровень, то ...
            for(int i=0; i<3; i++){digitalWrite(PinLED[i],0);} delay(1000);  //  Включаем  все светодиоды
            for(int i=0; i<3; i++){digitalWrite(PinLED[i],1);}               //  Выключаем все светодиоды
        }   delay(500);                                    //  Ждём пол секунды
        for(int i=0; i<=Level; i++){                       //  Выводим всю последовательность цветов ...
            delay(500); digitalWrite(PinLED[Task[i]],0);   //  Включаем  очередной светодиод
            delay(500); digitalWrite(PinLED[Task[i]],1);   //  Выключаем очередной светодиод
        }
    }
}
