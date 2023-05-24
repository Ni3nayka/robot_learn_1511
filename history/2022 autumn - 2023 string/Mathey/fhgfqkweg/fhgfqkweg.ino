const int horinzotal_1 = 8;
const int horinzotal_2 = 7;
const int horinzotal_3 = 6;
const int horinzotal_4 = 5;


const int vertical_1 = 4;
const int vertical_2 = 3;
const int vertical_3 = 2;
const int vertical_4 = 9;

int qwerty = 0;





void setup() {
  pinMode(horinzotal_1, OUTPUT);
  pinMode(horinzotal_2, OUTPUT);
  pinMode(horinzotal_3, OUTPUT);
  pinMode(horinzotal_4, OUTPUT);
  pinMode(vertical_1, INPUT_PULLUP);
  pinMode(vertical_2, INPUT_PULLUP);
  pinMode(vertical_3, INPUT_PULLUP);
  pinMode(vertical_4, INPUT_PULLUP);
  Serial.begin(9600);
}

String password = "B8CD";
String test_password = "";


void loop() {
  char a = button();
  if (a == '#') {
    if (qwerty == 1) {
      qwerty = 2;
    }

    else if (qwerty == 2) {
      password = test_password;
      test_password = "";
      qwerty = 0;
    }





    else {
      if (test_password == password) {
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
    if (qwerty == 1) {
      qwerty = 0;
    }

  }

  // Serial.println( button());
}

char get_matrix() {
  digitalWrite(horinzotal_1, 0);
  digitalWrite(horinzotal_2, 1);
  digitalWrite(horinzotal_3, 1);
  digitalWrite(horinzotal_4, 1);

  if (digitalRead(vertical_1) == 0) return '1';
  if (digitalRead(vertical_2) == 0) return '2';
  if (digitalRead(vertical_3) == 0) return '3';
  if (digitalRead(vertical_4) == 0) return 'A';

  digitalWrite(horinzotal_1, 1);
  digitalWrite(horinzotal_2, 0);
  digitalWrite(horinzotal_3, 1);
  digitalWrite(horinzotal_4, 1);

  if (digitalRead(vertical_1) == 0) return '4';
  if (digitalRead(vertical_2) == 0) return '5';
  if (digitalRead(vertical_3) == 0) return '6';
  if (digitalRead(vertical_4) == 0) return 'B';

  digitalWrite(horinzotal_1, 1);
  digitalWrite(horinzotal_2, 1);
  digitalWrite(horinzotal_3, 0);
  digitalWrite(horinzotal_4, 1);

  if (digitalRead(vertical_1) == 0) return '7';
  if (digitalRead(vertical_2) == 0) return '8';
  if (digitalRead(vertical_3) == 0) return '9';
  if (digitalRead(vertical_4) == 0) return 'C';

  digitalWrite(horinzotal_1, 1);
  digitalWrite(horinzotal_2, 1);
  digitalWrite(horinzotal_3, 1);
  digitalWrite(horinzotal_4, 0);

  if (digitalRead(vertical_1) == 0) return '*';
  if (digitalRead(vertical_2) == 0) return '0';
  if (digitalRead(vertical_3) == 0) return '#';
  if (digitalRead(vertical_4) == 0) return 'D';
  return '$';



}

char button() {
  while (get_matrix() == '$');
  char a = get_matrix();
  while (get_matrix() == a);
  return a;
}
