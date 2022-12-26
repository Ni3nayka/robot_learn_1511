#include <Wire.h> 
#include <iarduino_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor motor_R(0x0A);
iarduino_I2C_Motor motor_L(0x0B);

#include <iarduino_I2C_Bumper.h> 
iarduino_I2C_Bumper bum(0x0C);

int motor_speed = 100;

#define PIN_TRIG 5
#define PIN_ECHO 4

long duration, cm;

void setup() {
  delay(500);
  motor_R.begin(); 
  motor_L.begin(); 

  bum.begin();
  
  Serial.begin(9600);

  motor_R.setDirection(true);
  motor_L.setDirection(false);
  
  //Определяем вводы и выводы
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  //motors(100,100);
  //delay(2000);
  //motors(0,0);

  motors(100,100);
}

int D = 0;
int e_old = 0;

int I = 0;

void loop() {
  rastoyanie();
  
  //int e = bum.getLineAnalog(2) - bum.getLineAnalog(8);
  int e = cm - 50;
  
  int P = e*0.3;
  D = D + (e - e_old)*0.02;
  e_old = e;
  I = (I + e)*0.02;
  

  int PID = P;
  motors(70+PID,70-PID);
  
  
  
}

void rastoyanie() {
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

  //Serial.print("Расстояние до объекта: ");
  //Serial.print(cm);
  //Serial.println(" см.");

  // Задержка между измерениями для корректной работы скеча
  //delay(250);
}

void motors(int speed_L, int speed_R) {
  motor_R.setSpeed(speed_R, MOT_PWM);
  motor_L.setSpeed(speed_L, MOT_PWM);
}
