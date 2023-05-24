const int horizontal_1 = 8;
const int horizontal_2 = 7;
const int horizontal_3 = 6;
const int horizontal_4 = 5;

const int vertical_1 = 4;
const int vertical_2 = 3;
const int vertical_3 = 2;

String password = "1234";
String test_password = "";

void setup() {
  pinMode(horizontal_1,OUTPUT);
  pinMode(horizontal_2,OUTPUT);
  pinMode(horizontal_3,OUTPUT);
  pinMode(horizontal_4,OUTPUT);
  pinMode(vertical_1,INPUT_PULLUP);
  pinMode(vertical_2,INPUT_PULLUP);
  pinMode(vertical_3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  char a = button();
  if (a=='#') {
    if (qwerty==1) {
      qwerty = 2;
    }
    else if (qwerty==2) {
      password = test_password;
      test_password = "";
    }
    else {
        if (test_password==password) {
          Serial.println("yes");
          qwerty = 1;
        }
        else {
          Serial.println("no");
          qwerty = 0;
        }
        Serial.println(test_password);
        test_password = "";
    }
    
  }
  else {
    test_password += a;
    if (qwerty==1) {
      qwerty = 0;
    }
  }

  //Serial.println(button());
}

char button() {
  while (get_matrix()=='-');
  char a = get_matrix();
  while (get_matrix()==a);
  return a;
}

char get_matrix() {
  digitalWrite(horizontal_1,0);
  digitalWrite(horizontal_2,1);
  digitalWrite(horizontal_3,1);
  digitalWrite(horizontal_4,1);
  if (digitalRead(vertical_1)==0) return '1';
  if (digitalRead(vertical_2)==0) return '2';
  if (digitalRead(vertical_3)==0) return '3';
  
  digitalWrite(horizontal_1,1);
  digitalWrite(horizontal_2,0);
  digitalWrite(horizontal_3,1);
  digitalWrite(horizontal_4,1);
  if (digitalRead(vertical_1)==0) return '4';
  if (digitalRead(vertical_2)==0) return '5';
  if (digitalRead(vertical_3)==0) return '6';
  
  digitalWrite(horizontal_1,1);
  digitalWrite(horizontal_2,1);
  digitalWrite(horizontal_3,0);
  digitalWrite(horizontal_4,1);
  if (digitalRead(vertical_1)==0) return '7';
  if (digitalRead(vertical_2)==0) return '8';
  if (digitalRead(vertical_3)==0) return '9';
  
  digitalWrite(horizontal_1,1);
  digitalWrite(horizontal_2,1);
  digitalWrite(horizontal_3,1);
  digitalWrite(horizontal_4,0);
  if (digitalRead(vertical_1)==0) return '*';
  if (digitalRead(vertical_2)==0) return '0';
  if (digitalRead(vertical_3)==0) return '#';
  
  return '-';
}
