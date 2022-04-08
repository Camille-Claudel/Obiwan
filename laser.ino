#include <Servo.h>

Servo sx;
Servo sy;

void setxy(double x, double y)
{
  double d = 0.3
  sx.write(90 + degrees(atan2(x, d)));
  sx.write(90 - degrees(atan2(y, sqrt(sq(d) + sq(x)))));
}

void setup() {
  sx.attach(2);
  sy.attach(3);
}

void setcircular(double r, double angle) {
  double x = cos(radians(angle)) * r
  double y = sin(radians(angle)) * r
}

void loop() {
  // put your main code here, to run repeatedly:

}
