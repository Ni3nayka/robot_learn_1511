long int cxtnxbr = 0 ;
bool  erl1 , erl2, err1, err2;
void setup() {
  attachInterrupt(5, ghthsdfybt1, CHANGE);
  attachInterrupt (4, ghthsdfybt2, CHANGE);
  erl1 = digitalRead(18);
  erl2 = digitalRead(19);
  err1 = erl1;
  err2 = erl2;
  Serial.begin (9600);
}

void loop() {
  // put your main code here, to run 
  Serial.println ( cxtnxbr);
}
void ghthsdfybt1 () {
  err1 = (!err1);
  jgthfnbyuR();

}
void ghthsdfybt2 () {
  err2 = (!err2);
  jgthfnbyuR();
}
void jgthfnbyuR() {
if ( erl1!=err2) cxtnxbr++;
else cxtnxbr--;

erl1=err1;
erl2=err2;   
}
