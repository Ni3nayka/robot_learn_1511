#include <Wire.h>               

#include <iarduino_I2C_Motor.h>   
iarduino_I2C_Motor mot_R(0x0A);     
iarduino_I2C_Motor mot_L(0x0B);   

#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);  

#define PIN_TRIG 12
#define PIN_ECHO 11

void setup(){       
    delay(500); 
    Serial.begin(9600);
    //Определяем вводы и выводы
    pinMode(PIN_TRIG, OUTPUT);
    pinMode(PIN_ECHO, INPUT);
    mot_R.begin();
    mot_L.begin();
    bum.begin();

    mot_R.setDirection(true);
    mot_L.setDirection(false);
    
    mot_R.setSpeed( 0, MOT_PWM);
    mot_L.setSpeed( 0, MOT_PWM);

    test_coordinata();
    
}


bool test_coordinata() {
  for (int i = 1; i<=9;i++) {
    if (bum.getLineAnalog(i)<1000) {
      return 0;
    }
  }
  return 1;
}

unsigned long int t = 0;

void loop(){ 
  if (millis()-t>8000) {
    motor(0,0);
    while (1) 
      delay(1000);
  }
  if (test_distance()>25) {
    motor(-20,20);
  }
  else {
    motor(100,100);
    while (test_coordinata()) {
      delay(10);
    }
    motor(0,0);
    delay(100);
    motor(-100,-100);
    delay(1000);
    t = millis();
  }
}

int test_distance() {

  long duration, cm;
  
  // Сначала генерируем короткий импульс длительностью 2-5 микросекунд.

  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  // Выставив высокий уровень сигнала, ждем около 10 микросекунд. В этот момент датчик будет посылать сигналы с частотой 40 КГц.
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  //  Время задержки акустического сигнала на эхолокаторе.
  duration = pulseIn(PIN_ECHO, HIGH);

  // Теперь осталось преобразовать время в расстояние
  cm = (duration / 2) / 29.1;

  // Задержка между измерениями для корректной работы скеча
  delay(250);

  return cm;
}


void motor(int a, int b) {
  mot_R.setSpeed(a, MOT_PWM);
  mot_L.setSpeed(b, MOT_PWM);
}
