import processing.serial.*;
Serial usb;

void setup() {
  background(#48DCE0); // 0-255 - черный-белый; 0,100,255 - голубой RGB; #E04848 
  size(1000,800); // размер окна, есть fullscreen
  
  usb = new Serial(this, "COM23", 9600);
  usb.bufferUntil('\n');
  
  X = width/2; 
  Y = height/2;
  R = 50;
}

float X = width/2; 
float Y = height/2;
float R = 25;
float stepY = 5;
float stepX = 5;

float X_R, Y_R; 

void draw() {
  background(#48DCE0); // залить фон
  
  fill(255,255,0); // color next object
  //circle(500,400,50); // x,y,D
  Y=Y+stepY;
  X=X+stepX;
  if (Y>height-R || Y<R || Y==height-100 && X>mouseX-100 && X<mouseX+100) stepY=-stepY;
  if (X>width-R || X<R) stepX=-stepX;
  circle(X,Y,R*2);

  fill(255,0,0); // color next object
  //X_R = constrain(mouseX-100,0,width-200);
  Y_R = height-50;
  rect(X_R,Y_R,200,20);
  
  
}

void serilaEvent(Serial usb) {
  X_R = float(usb.readStringUntil('\n'));
}
