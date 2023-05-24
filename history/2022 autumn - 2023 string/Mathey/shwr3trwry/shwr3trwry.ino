#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);

#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor mot_L(0x0B);
iarduino_I2C_Motor mot_R(0x0A);

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200


int Object = 1;
int cm = 0;

unsigned long int time = 0;
void stop() {
  while (1);
}


void setup() {
  pinMode (TRIGGER_PIN, OUTPUT);
  pinMode (ECHO_PIN , INPUT);

  delay(500);
  mot_L.begin();
  mot_R.begin();
  mot_L.setDirection(false);
  Serial.begin (9600);
  bum.begin();
  time = millis();
  //secondgear();
  /* ponchik();
    ponchik();
    bankai_senbonzakura();
    ponchik();
    ponchik();
    tryhodra();
    ponchik();
    ponchik();
    ponchik();
    tryhodra();
    ponchik();
    ponchik();
    tryhodra();
    ponchik();
    delay(500);
    bankai_senbonzakura();
    bankai_senbonzakura();
    ponchik();
    tryhodra();
    ponchik();
    ponchik();
    tryhodra();
    ponchik();
    ponchik();
    ponchik();
    tryhodra();
    ponchik();
    ponchik();
    bankai_senbonzakura();
    ponchik();
    bankai_senbonzakura();
    bankai_senbonzakura();
    motor(-50,-50);
    delay(1100);
    motor(0,0);*/


  ponchik();
  ponchik();
  bankai_senbonzakura();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  tryhodra();
  tryhodra();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  bankai_senbonzakura();
  ponchik();
  bankai_senbonzakura();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  tryhodra();
  tryhodra();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  bankai_senbonzakura();
  ponchik();
  bankai_senbonzakura();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  tryhodra();
  tryhodra();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  bankai_senbonzakura();
  ponchik();
  bankai_senbonzakura();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  tryhodra();
  tryhodra();
  Ananas();
  if (cm < 15) {
    ponchik();
    stop ();
  }
  else if (cm < 40) {
    ponchik();
    ponchik();
    stop();
  }
  bankai_senbonzakura();












}






long int I = 0;
void loop() {
  Ananas();
  Serial.println(cm);
}




void motor(int l , int r) {
  mot_R.setSpeed(  r, MOT_PWM);
  mot_L.setSpeed(  l, MOT_PWM);
}
void secondgear() {
  motor(30, -30);
  delay(200);
  while (bum.getLineAnalog(5) > 2250) {
    motor (100, 100);
  }
  motor(-100, -100);
  delay(1000);
  motor(0, 0);
}



void ponchik () {


  while (bum.getLineAnalog(1) > 1500 && bum.getLineAnalog(9) > 1500 ) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e * 0.035;
    motor (80 + P, 80 - P);
  }
  time = millis();
  while (time + 420 > millis()) {
    int e = (bum.getLineAnalog(3) - bum.getLineAnalog(7));
    int P = e * 0.035;
    motor (80 + P, 80 - P);
  }



  motor (0, 0);
}


void bankai_senbonzakura () {
  motor (-80, 80);
  Object = 0;
  while ( bum.getLineAnalog(1) < 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }

  }
  while ( bum.getLineAnalog(1) > 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }
  }
  while ( bum.getLineAnalog(1) < 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }
  }

  motor(0, 0);
}

void tryhodra () {
  motor (80, -80);
  while ( bum.getLineAnalog(9) < 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }
  }
  while ( bum.getLineAnalog(9) > 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }
  }
  while ( bum.getLineAnalog(9) < 1500) {
    Ananas ();
    if (cm < 15) {
      Object = 1;
    }


  }
  motor(0, 0);
}

void Ananas () {
  digitalWrite (TRIGGER_PIN, 0);
  delayMicroseconds (5);
  digitalWrite(TRIGGER_PIN, 1);
  delayMicroseconds(10);
  digitalWrite (TRIGGER_PIN, 0);
  int duration = pulseIn(ECHO_PIN, 1);
  cm = (duration / 2) / 29.1;
  delay (10);


}
