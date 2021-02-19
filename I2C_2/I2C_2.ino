#include <Wire.h> //COM6
void setup() {
  Wire.begin(1);
  Wire.onReceive(aaa);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
void loop() {
  delay(70);
}
void aaa(int a){
  int x=Wire.read();
  if(x<20){
    digitalWrite(13,1);
  }else{
    digitalWrite(13,0);
  }
  Serial.println(x);
}
