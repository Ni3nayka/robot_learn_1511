#include <LiquidCrystal.h>     // Подключаем библиотеку LiquidCrystal для работы с LCD дисплеем
#include <iarduino_DHT.h>      // Подключаем библиотеку iarduino_DHT  для работы с DHT датчиком
LiquidCrystal lcd(2,3,4,5,6,7);// Создаём объект библиотеки LiquidCrystal, выводы дисплея (RS,E,D4,D5,D6,D7)
iarduino_DHT  sensor(12);      // Создаём объект библиотеки iarduino_DHT, указывая вывод датчика (SDA)
const uint8_t PinRes = A0;     // Создаём константу с номером входа, к которому подключён фоторезистор
      int     ValRes;          // Создаём переменную для хранения напряжения снятого с фоторезистора
      uint8_t symbol[7][8] = { // Создаём массив из семи символов, для их записи в ОЗУ дисплея
                                  { 6, 9, 9, 6, 0, 0, 0,0} /* ° */, {14,10,10,10,31,17,17,0} /* Д */,
                                  {16,16,16,30,17,17,30,0} /* Ь */, {17,17,17,15, 1, 1, 1,0} /* Ч */,
                                  {31,17,17,17,17,17,17,0} /* П */, { 7, 9,17,17,17,17,17,0} /* Л */,
                                  {17,17,17,15, 1, 1,14,0} /* У */  };
void setup(){
    lcd.begin(16, 2);          // Инициируем работу с LCD дисплеем (всего столбцов, строк)
    for(int i=0; i<7; i++){lcd.createChar(i+1, symbol[i]);}
}
void loop(){
    ValRes=analogRead(PinRes); // Читаем значение напряжения со входа PinRes в переменную ValRes
    sensor.read();             // Читаем показания температуры и влажности с датчика DHT11
                                  lcd.setCursor(0, 0); lcd.print((String) sensor.tem+"\1C");  // температура
                                  lcd.setCursor(0, 1); lcd.print((String) sensor.hum+" %");   // влажность
    if(ValRes>100){               lcd.setCursor(12,0); lcd.print("\2EH\3");                   // ДЕНЬ
        if(ValRes>350){           lcd.setCursor(8, 1); lcd.print("CO\6HE\4HO");               // СОЛНЕЧНО
        }else{                    lcd.setCursor(8, 1); lcd.print("\5ACM\7PHO");}              // ПАСМУРНО
    }else{                        lcd.setCursor(12,0); lcd.print("HO\4\3");                   // НОЧЬ
                                  lcd.setCursor(8, 1); lcd.print("          ");}              // ПУСТО
    delay(1000);               // Приостанавливаем выполнение программы на 1 секунду
}
