#include <Servo.h>

Servo sx;
Servo sy;
double d = 8;
double e = 2;
double cx=0;//current x
double cy=0;//curent y

void setxy(double x, double y)
{
  cx=x;
  cy=y;
  //sx.write(90 + 2*degrees(atan2(x, d)));
  //sy.write(90 - degrees(atan2(y, sqrt(sq(d) + sq(x)))));
  sx.write(90 + 2*degrees(atan2(x, d)+asin(e/sqrt(sq(d)+sq(x)))));
  sy.write(95 - degrees(atan2(y, sqrt(sq(d) + sq(x) - sq(e)))));
}

void getcircular(double r, double angle, double &x, double &y) {
  x = cos(radians(angle)) * r;
  y = sin(radians(angle)) * r;
}

void drawline(double x,double y, int stops){
  double x0=cx;
  double y0=cy;
  for (int i=1; i<=stops; i++){
    double xd= (i*x+(stops-i)*x0)/stops;
    double yd= (i*y+(stops-i)*y0)/stops;
    setxy(xd,yd);
    delay(30);
  }
}

void drawpentagram(double r,double x0, double y0){
  double x = 0;
  double y = 0;
  for (int i = 144; i <= 720; i += 144){
    getcircular(r,i,x,y);
    drawline(x+x0,y+y0,20);
    //Serial.println("hey j'ai fait une ligne");
  }
}
void drawcircle(double r,double x0, double y0){
  double x = 0;
  double y = 0;
  for (int i = 0; i < 360; i += 1){
    getcircular(r,i,x,y);
    setxy(x,y);
    delay(10);
    Serial.println("hey j'ai fait un degré");
  }
  
  
}

void setup() {
  sx.attach(2);
  sy.attach(3);
  setxy(0,0);
  //delay(5000);
  //Serial.begin(9600);
}

void loop() {
  drawpentagram(4, 0, .5);
  drawcircle(4, 0, .5);
  
  //Serial.println("hey j'ai fait un pentagram");
  

}
