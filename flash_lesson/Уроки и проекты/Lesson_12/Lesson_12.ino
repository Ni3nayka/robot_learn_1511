#include <Adafruit_Fingerprint.h>                               // подключаем библиотеку для работы с модулем отпечатков пальцев
#include <SoftwareSerial.h>                                     // подключаем библиотеку для работы с программным UART
SoftwareSerial       mySerial(2, 3);                            // объявляем объект mySerial для работы с библиотекой SoftwareSerial ИМЯ_ОБЪЕКТА( RX, TX ); // Можно указывать любые выводы, поддерживающие прерывание PCINTx
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);  // объявляем объект finger   для работы с библиотекой Adafruit_Fingerprint ИМЯ_ОБЪЕКТА = Adafruit_Fingerprint(ПАРАМЕТР); // ПАРАМЕТР - ссылка на объект для работы с UART к которому подключен модуль, например: &Serial1
void setup(){
  while(!Serial);                                               // Ожидание инициализации аппаратного UART
  delay(500);                                                   // Ожидание инициализации модуля отпечатков пальцев
  Serial.begin(9600);                                           // Инициализация аппаратного UART на скорости 9600
  Serial.println("Scan sensor...");                             // Вывод сообщения "Поиск сенсора"
  finger.begin(57600);                                          // Инициализация программного UART на скорости 57600 (скорость модуля по умолчанию)
  if(finger.verifyPassword()){Serial.println("Found sensor!");} // Если модуль отпечатков    обнаружен, выводим сообщение "сенсор обнаружен"
  else{Serial.println("Did not find sensor :("); while(1);    } // Если модуль отпечатков не обнаружен, выводим сообщение "сенсор не обнаружен" и входим в бесконечный цикл: while(1);
  uint8_t  templateBuffer[256];                                 // Создание массива,    для хранения пикселей модели (шаблона) отпечатка пальца
  int      index;                                               // Создание переменной, для хранения количества записанных элементов в массив templateBuffer
  uint32_t starttime;                                           // Создание переменной, для хранения времени начала приёма пикселей по программному UART
  for (int id = 0; id < 10; id++){                              // Проход по 10 идентификаторам
    if(finger.loadModel(id) == FINGERPRINT_OK)  { Serial.print("template "); Serial.print(id); Serial.println(" loaded");       // Загрузка модели в буфер, если результат выполнения равен константе FINGERPRINT_OK (модель загружена), то проходим дальше
    if(finger.getModel()    == FINGERPRINT_OK)  { Serial.print("template "); Serial.print(id); Serial.println(" transferring"); // Получение модели из буфера, если результат выполнения равен константе FINGERPRINT_OK (передача инициирована), то проходим дальше
      index=0; starttime = millis();                            // Обнуляем количество записанных элементов и обновляем время старта приёма данных
      while ((millis() - starttime) < 1000){                    // Если с начала приёма данных прошло менее 1 секунды, то ...
        if (mySerial.available()){                              // Если в буфере программного UART имеются данные для чтения, то ...
          if(index < 256){                                      // Если принято меньше 256 байт, то ...
            templateBuffer[index] = mySerial.read(); index++;   // Сохраняем очередной байт, принятый по программному UART, в очередной элемент массива templateBuffer
          }
        }
      }                            Serial.print("template "); Serial.print(id); Serial.print(" array("); Serial.print(index); Serial.println(" bytes):");
      for(int i=0; i<index; i++) { Serial.print("\t0x"); Serial.print(templateBuffer[i],HEX);
        if((i+1)%16==0)          { Serial.println("");}
      }
    }else                        { Serial.print("template "); Serial.print(id); Serial.println(" not transferring");}
    }else                        { Serial.print("template "); Serial.print(id); Serial.println(" not found");}
  }
}
void loop(){}
