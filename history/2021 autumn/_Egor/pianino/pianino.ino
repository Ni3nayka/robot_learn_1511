const int n_button = 5;
const int first_button = 8;
int button[n_button] = {0};
const int zum = 13;

void setup() {
  for (int i = 0; i < n_button; i++) { 
    button[i] = first_button+i;
    pinMode(button[i],INPUT_PULLUP);
  } 
}

void loop() {
  int n = button_read();
  if (n) tone(zum,n);
  else noTone(zum);
}

int button_read() {
  int n = 0;
  for (int i = 0; i < n_button; i++) {
    n+=!digitalRead(button[i])*(i+1)*100;
  }
  return n;
}
