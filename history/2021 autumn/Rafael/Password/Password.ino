const int button[3] = {8, 9, 10};
int h[10] = {0};
int t[10] = {1, 2, 2, 1};
int M = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button[0], INPUT_PULLUP);
  pinMode(button[1], INPUT_PULLUP);
  pinMode(button[2], INPUT_PULLUP);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(button[0]) == 0) {
      h[M] = 1;
      M++;
      delay(500);
    }
    if (digitalRead(button[1]) == 0) {
      h[M] = 2;
      M++;
      delay(500);
    }
  }


  if (digitalRead(button[2]) == 0) {
    for (int i = 0; i < 10; i++)
      Serial.print(h[i]);
    Serial.println();
    bool flag = true;
    for (int i=0; i<10; i++) {
      if (h[i]==t[i]){}
      else { flag = false; break; }
      
      
    }
    if (flag) Serial.println("yes");
    else Serial.println("no");

    for (int i=0; i<10; i++) h[i]=0;
    M=0;
    delay(1000);
  }
}
