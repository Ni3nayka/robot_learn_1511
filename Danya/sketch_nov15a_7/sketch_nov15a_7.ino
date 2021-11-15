const int batten1 = 5;
const int batten2 = 6;
const int batten3 = 7; 
int h[10]={0};
int t[10]={1,2,1,2};
void setup() {Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(batten1,INPUT_PULLUP);
pinMode(batten2,INPUT_PULLUP);
pinMode(batten3,INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print((digitalRead(batten1)));
Serial.print((digitalRead(batten2)));
Serial.println((digitalRead(batten3)));
if ((digitalRead(batten1))==0)
}
