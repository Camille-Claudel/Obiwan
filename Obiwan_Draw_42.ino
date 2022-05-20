#include <Servo.h>

Servo sx;
Servo sy;
double d = 9;
double e = 2;
double cx=0;//current x
double cy=0;//curent y

void setxy(double x, double y)
{
  cx=x;
  cy=y;
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

int kEnDePos[] = {
0, 0,
34, 2,
0, 1,
34, 18,
20, 18,
20, 24,
34, 69,
41, 68,
41, 24,
50, 24,
50, 18,
41, 18,
41, 2,
0, 0,
34, 24,
0, 1,
11, 24,
34, 56,
34, 24,
0, 0,
59, 2,
0, 1,
59, 14,
68, 25,
78, 33,
89, 45,
89, 56,
84, 62,
71, 62,
60, 54,
60, 63,
70, 69,
85, 69,
93, 65,
97, 56,
97, 44,
86, 30,
75, 22,
68, 15,
67, 9,
99, 9,
99, 2,
59, 2,
0, 0
};

//           pos x       , pos y        , size 
void kEnDe(double setupX, double setupY, double setupS) {
  
  for (int i = 0; i<88; i += 2){
    //Serial.println(i .. " [" .. kEnDePos[i] .. "," .. kEnDePos[i + 1] .. "]" );
    if (kEnDePos[i] == 0) {
      if (kEnDePos[i+1] == 0) {
        digitalWrite(4,HIGH);
        delay(300);
      }
      else {
        digitalWrite(4,LOW);
        delay(300);
      }
    }
    else{
      /*Serial.print("\n Info ");
      Serial.print(i);
      Serial.print(" : ");
      Serial.print(kEnDePos[i]);
      Serial.print(" , ");
      Serial.print(kEnDePos[i + 1]);*/
      setxy((setupX + kEnDePos[i]) * setupS , (setupY + kEnDePos[i + 1])* setupS ); 
    }
  }
}


void setup() {
  sx.attach(2);
  sy.attach(3);
  pinMode(4,OUTPUT);
  setxy(0,0);
  //delay(5000);
  //Serial.begin(9600);
}

void loop() {
  kEnDe(-40,-40,0.1);
  delay(100);
  //drawpentagram(4, 0, .5);
  //drawcircle(4, 0, .5);
  
  //Serial.println("hey j'ai fait un pentagram");
  

}
