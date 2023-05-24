#define DIR_L 4
#define PWM_L 5
#define DIR_R 7
#define PWM_R 6

void setup() {
  pinMode (DIR_L, OUTPUT);
  pinMode (PWM_L, OUTPUT);
  pinMode (DIR_R, OUTPUT);
  pinMode (PWM_R, OUTPUT);


  //  digitalWrite (DIR_L, 1);
  //  analogWrite (PWM_L, 250);
  //  digitalWrite (DIR_R, 1);
  //  analogWrite (PWM_R, 250);
  //  delay (1000);
  //  analogWrite (PWM_L, 0);
  //  analogWrite (PWM_R, 0);

  Serial.begin(9600);





}

void loop() {
int b =  analogRead(A2);
int a =  analogRead(A3);

 int P = b-a;
 P =P*0.1;
 digitalWrite (DIR_L, 1);
 analogWrite (PWM_L, 50-P);
 digitalWrite (DIR_R, 1);
 analogWrite (PWM_R, 50+P);


}
