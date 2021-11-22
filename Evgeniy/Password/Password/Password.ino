const int button[3] = {8, 9, 10};
#define enter digitalRead(button[2])==0
int history[10] = {0};
int password[10] = {0};
int P = 0;
int M = 0;
int t = 0;
int t2 = 0;
int mode_work = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
    pinMode (button[i], INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button[0]) == 0) {
    history[M] = 1;
    M++;
    while (digitalRead(button[0]) == 0);
  }
  if (digitalRead(button[1]) == 0) {
    history[M] = 2;
    M++;
    while (digitalRead(button[1]) == 0);
  }

  if (enter) { 
    int t = millis();  
    while (enter) {
      delay(50);
    }
    int t2 = millis();
    t = t2 - t;
    for (int i = 0; i < 10; i++) Serial.print(history[i]); Serial.println();
    if (t > 1000)
    {
      mode_work = 1;
      Serial.println("password changer is active");
    }
    else
    { 
      if (mode_work == 1){save_pass(); mode_work = 0;}
      else {pass_mode();}
    }
    
  }
  
}

void pass_mode(){
  bool flag = true;
    for (int i = 0; i < 10; i++) {
      if (history[i] != password[i]) {
        flag = false;
        break;
      }
    }
    if (flag == true) Serial.println("yes");
    else Serial.println("no");

    for (int i = 0; i < 10; i++) history[i] = 0;
    M = 0;}
void save_pass(){
  for (int i = 0; i < 10; i++)
  password[i] = history[i];
  M = 0;}
