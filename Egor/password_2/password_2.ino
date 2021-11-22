const int button[3] = {8,9,10};
int history[10] = {0};
int password[10] = {1,2,1,2};
int M = 0;

int work_mode = 0;

#define enter digitalRead(button[2])==0

void setup() {
  Serial.begin(9600);
  for (int i=0; i<3; i++) 
    pinMode(button[i], INPUT_PULLUP);
  
}

void loop() {
  //for (int i=0; i<3; i++)
  //  Serial.print(digitalRead(button[i]));
  //Serial.println();
  
  for (int i=0; i<2; i++)
    if (digitalRead(button[i])==0) { 
      history[M] = i+1; M++; 
      while(digitalRead(button[i])==0) delay(50); 
    }

  if (enter) {
    unsigned long int t1 = millis();
    while (enter) { delay(50); }
    unsigned long int t2 = millis();
    unsigned long int t = t2-t1;
    if (t>1000) {
      work_mode = 1;
      Serial.println("input password");
    }
    else { // pass_test
      for (int i=0; i<10; i++)
        Serial.print(history[i]);
      Serial.println();
      if (work_mode==1) { // запомнить новый пароль
        save_pass();
      }
      else { // сравнпить с эталонным паролем
        pass_test();
      }
    }
    for (int i=0; i<10; i++) history[i]=0;
    M=0;
  }
}

void save_pass() {
  for (int i=0; i<10; i++) 
    password[i] = history[i];
  M=0;
  Serial.println("password is save");
}

void pass_test() {
  bool flag = true;
  for (int i=0; i<10; i++) {
    if (history[i]!=password[i]) { flag = false; break; }
  }
  if (flag==true) Serial.println("yes");
  else Serial.println("no");
}
