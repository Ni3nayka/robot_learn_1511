[![](https://iarduino.ru/img/logo.svg)](https://iarduino.ru)[![](https://wiki.iarduino.ru/img/git-shop.svg?3)](https://iarduino.ru) [![](https://wiki.iarduino.ru/img/git-wiki.svg?2)](https://wiki.iarduino.ru) [![](https://wiki.iarduino.ru/img/git-lesson.svg?2)](https://lesson.iarduino.ru)[![](https://wiki.iarduino.ru/img/git-forum.svg?2)](http://forum.trema.ru)

# iarduino\_HC\_SR04\_int

**This is a library for Arduino IDE. It allows to work with [Ultrasound distance sensor HC-SR04](https://iarduino.ru/shop/Sensory-Datchiki/ultrazvukovogo-datchika-hc-sr04-rasstoyaniya-dvizheniya.html) module**

**Данная библиотека для Arduino IDE позволяет работать с модулем [Ультразвуковой датчик HC-SR04](https://iarduino.ru/shop/Sensory-Datchiki/ultrazvukovogo-datchika-hc-sr04-rasstoyaniya-dvizheniya.html)**

> Подробнее про установку библиотеки читайте в нашей [инструкции](https://wiki.iarduino.ru/page/Installing_libraries/).

> Подробнее про подключение к [Arduino UNO](https://iarduino.ru/shop/boards/arduino-uno-r3.html)/[Piranha UNO](https://iarduino.ru/shop/boards/piranha-uno-r3.html) читайте на нашей [wiki](https://wiki.iarduino.ru/page/ultrazvukovoy-datchik-izmereniya-rasstoyaniya-hc-sr04/#h3_3)


| Модель | Ссылка на магазин |
|---|---|
| <p>Ультразвуковой датчик расстояния HC-SR04</p> <img src="https://wiki.iarduino.ru/img/resources/70/70.svg" width="150px"></img>| https://iarduino.ru/shop/Sensory-Datchiki/ultrazvukovogo-datchika-hc-sr04-rasstoyaniya-dvizheniya.html |


Данная библиотека использует внешнее прерывание, поэтому вывод ECHO датчика может быть подключён только к выводу Arduino использующему внешнее прерывание. Но благодаря прерыванию, библиотека не приостанавливает выполнение кода при ожидании ответа от датчика, которое может достигать 38 мс. Если Ваш код не критичен к таким задержкам, воспользуйтесь библиотекой без внешнего прерывания [iarduino\_HC\_SR04.h](https://github.com/tremaru/iarduino_HC_SR04), при использовании которой, датчики можно подключать к любым выводам Arduino. Синтаксис обеих библиотек одинаков.


## Назначение функций:

**Подробное описание работы с библиотекой и примеры смотрите на [нашем сайте]()**

```C++
#include <iarduino_HC_SR04_int.h> // Подключаем библиотеку
iarduino_HC_SR04_int ОБЪЕКТ( ВЫВОД_TRIG , ВЫВОД_ECHO ); // Создаём объект.
```

**Расстояние в см** 

```C++
ОБЪЕКТ.distance( [ ТЕМПЕРАТУРА ] ); // Возвращает расстояние в см, принимая, в качестве необязательного параметра, температуру воздуха.
```

**Коэффициент усреднения** 

```C++
ОБЪЕКТ.averaging; // Положительное целое число - коэффициент усреднения показаний возвращаемых функцией distance().
```

