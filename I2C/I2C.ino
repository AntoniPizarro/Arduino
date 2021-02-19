#include <Wire.h> //COM4
long a,b;
void setup() {
  Wire.begin();
  pinMode(13,OUTPUT);
  pinMode(6,INPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  digitalWrite(5,0);
  delayMicroseconds(5);
  digitalWrite(5,1);
  delayMicroseconds(10);
  b=pulseIn(6,1);
  a=int(0.017*b);
  Wire.beginTransmission(1);
  Wire.write(a);
  Wire.endTransmission();
  delay(170);
}
