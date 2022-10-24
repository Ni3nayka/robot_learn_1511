const int PinR1 = A1;  //  Объявляем константу с № входа  к которому подключён фоторезистор1
const int PinR2 = A2;  //  Объявляем константу с № входа  к которому подключён фоторезистор2
const int PinR3 = A3;  //  Объявляем константу с № входа  к которому подключён фоторезистор3
const int PinR4 = A4;  //  Объявляем константу с № входа  к которому подключён фоторезистор4
const int PinR5 = A5;  //  Объявляем константу с № входа  к которому подключён фоторезистор5
const int PinB  = 12;  //  Объявляем константу с № вывода к которому подключён зуммер
      int ValR;        //  Объявляем переменную для хранения значения освещения ниже среднего
      int ValF;        //  Объявляем переменную для хранения суммарной частоты выбранных нот
      int ValS;        //  Объявляем переменную для хранения количества выбранных нот

void setup(){
    ValR=analogRead(PinR1)+analogRead(PinR2)+analogRead(PinR3)+analogRead(PinR4)+analogRead(PinR5);
    ValR/=7;
}

void loop(){
    ValF = ValS = 0;                                 //  Обнуляем переменные ValF и ValS
    if(analogRead(PinR1)<ValR){ValS++; ValF+=800; }  //  Увеличиваем количество нот ValS и частоту ValF
    if(analogRead(PinR2)<ValR){ValS++; ValF+=900; }  //  Увеличиваем количество нот ValS и частоту ValF
    if(analogRead(PinR3)<ValR){ValS++; ValF+=1000;}  //  Увеличиваем количество нот ValS и частоту ValF
    if(analogRead(PinR4)<ValR){ValS++; ValF+=1100;}  //  Увеличиваем количество нот ValS и частоту ValF
    if(analogRead(PinR5)<ValR){ValS++; ValF+=1200;}  //  Увеличиваем количество нот ValS и частоту ValF
    if(ValS){tone(PinB,(ValF/ValS));   delay(100);}  //  Если ValS>0, то выводим среднюю частоту на зуммер
    else { noTone(PinB); }                           //  Иначе останавливаем вывод звука
}
