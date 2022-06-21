const int button[3] = {8,9,10};
int history[10] = {0};
int password[10] = {1,2,1,2};
int M = 0;

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
    if (digitalRead(button[i])==0) { history[M] = i+1; M++; delay(500); }

  if (digitalRead(button[2])==0) {
    for (int i=0; i<10; i++)
      Serial.print(history[i]);
    Serial.println();

    bool flag = true;
    for (int i=0; i<10; i++) {
      if (history[i]!=password[i]) { flag = false; break; }
    }

    if (flag==true) Serial.println("yes");
    else Serial.println("no");

    for (int i=0; i<10; i++) history[i]=0;
    M=0;
    
  }
}
