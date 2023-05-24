const int M = 150;
#define sm  148
#define gradus 22
void setup() {
  setup1();

  while (get_encL() < 130*sm) {
    P_regulyator();
    //run_enc (14800, 14800);
  }
run_enc(0, 0);
run_enc(-95*gradus, 95*gradus);
while (analogRead (A1)>500){
  motor ( -150, 150);
  }
  run_enc (0,5*gradus);
  
}
void loop() {

}
void P_regulyator() {

  int e = -analogRead (A0) + analogRead (A1) ;
  int P = e * 0.55;


  motor (M - P, M + P);
  //Serial.println (analogRead (A1));
}
