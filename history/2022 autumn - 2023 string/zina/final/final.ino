const int M = 150;
#define sm  148
#define gradus 22

void setup() {
  setup1();
  distanse(50,52);
int i=0;
while (i<4){
  kycok();
  i++;
}

}
void loop() {
 
}
void P_regulyator() {

  int e = -analogRead (A0) + analogRead (A1) ;
  int P = e * 0.55;


  motor (M - P, M + P);
  
}
void kycok(){
 if (distanse(50,52)>40) 
{
  forward (30);
  back (30);
  
}
turnR (53);
if (distanse(50,52)<40){
  forward (25);
  back (25);
}
turnR(53);
  
 
}
