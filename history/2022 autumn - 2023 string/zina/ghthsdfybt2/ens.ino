const int PWMA = 10;
const int PWMB = 11 ;
const int DIRA = 12 ;
const int DIRB = 13 ;
long int encL = 0 ;
long int encR = 0 ;
bool  erl1 , erl2, err1, err2; // r - новый . l - старый // правый
bool  ell1 , ell2, elr1, elr2;//левый
#define Kp 0.9
#define Kd 10
#define Ki 0.01
#define Kip 0.9
void setup1() {
  attachInterrupt(5, interrupt1, CHANGE); // 5 из таблицы таблицу искать ; прерывание ардуино ;
  attachInterrupt (4, interrupt2, CHANGE);
  erl1 = digitalRead(18);
  erl2 = digitalRead(19);
  err1 = erl1;
  err2 = erl2;
  Serial.begin (9600);

  attachInterrupt(3, interrupt1L, CHANGE);
  attachInterrupt (2, interrupt2L, CHANGE);
  ell1 = digitalRead(20);
  ell2 = digitalRead(21);
  elr1 = ell1;
  elr2 = ell2;
  Serial.begin (9600);

}


void run_enc(long int L, long int R) {
  encR = 0;
  encL = 0;
  long int eR = 0, eR_old = 0;
  long int eL = 0, eL_old = 0;
  long int eror = 50;
  unsigned long int t = millis();
  long int Ir = 0, Pr, Dr, PIDr;
  long int Il = 0, Pl, Dl, PIDl;
  while (millis() - t < 1000) {
    if ( abs (eL) > eror || abs (eR) > eror)t = millis ();
    Serial.print( encR);
    Serial.print(" ");
    Serial.println( encL);
    eR = R - encR;
    Pr = eR;
    Ir = eR + Ir * Kip;
    Dr = eR - eR_old;
    PIDr = Pr * Kp + Dr * Kd + Ir * Ki;
    eR_old = eR;

    eL = L - encL;
    Pl = eL;
    Il = eL + Il * Kip;
    Dl = eL - eL_old;
    PIDl = Pl * Kp + Dl * Kd + Il * Ki;
    eL_old = eL;

    motor (PIDl, PIDr);


  } motor (0, 0);
}

void interrupt1 () {
  err1 = (!err1);
  enc_operationR();

}
void interrupt2 () {
  err2 = (!err2);
  enc_operationR();
}
void enc_operationR() {
  if ( erl1 != err2) encR++;
  else encR--;
  //err1 = digitalRead(18);
  //err2 = digitalRead(19);
  erl1 = err1;
  erl2 = err2;
}
void interrupt1L () {
  elr1 = (!elr1);
  enc_operationL();

}
void interrupt2L () {
  elr2 = (!elr2);
  enc_operationL();
}
void enc_operationL() {
  if ( ell1 != elr2) encL++;
  else encL--;
  //elr1 = digitalRead(20);
  //elr2 = digitalRead(21);
  ell1 = elr1;
  ell2 = elr2;
}
void motor (long int a , long int b ) {
  a = constrain (a, -255, 255);
  b = constrain (b , -255 , 255);
  analogWrite ( PWMA, abs (a));
  analogWrite ( PWMB, abs (b));
  digitalWrite (DIRA, a > 0);
  digitalWrite (DIRB, b > 0);
}
int get_encL () {
  return encL;
}
int get_encR () {
  return encR;
}
void zero_enc () {
  encR = 0;
  encL = 0;
}
void turnR (long int gr) {
  long int grp = gr * gradus;
  run_enc (grp, -grp);
}
void turnL (long int gr) {
  long int grp = gr * gradus;
  run_enc (-grp, grp);
}
void forward (long int sme) {
  long int smet = sme * sm;
  run_enc (smet,smet);
}
