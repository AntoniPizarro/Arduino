#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
void setup(){
  lcd.begin(16,2);
  pinMode(2,OUTPUT); //verde
  pinMode(3,OUTPUT); //azul
  pinMode(4,OUTPUT); //rojo
  pinMode(5,OUTPUT); //azul
  pinMode(6,OUTPUT); //verde
}
void verdea(){
  digitalWrite(2,1);
  digitalWrite(6,1);
}
void verdeb(){
  digitalWrite(2,0);
  digitalWrite(6,0);
}
void azula(){
  digitalWrite(3,1);
  digitalWrite(5,1);
}
void azulb(){
  digitalWrite(3,0);
  digitalWrite(5,0);
}
void rojoa(){
  digitalWrite(4,1);
}
void rojob(){
  digitalWrite(4,0);
}
void drop(int a){
  verdea();
  azulb();
  rojob();
  delay(a);
  verdeb();
  azula();
  rojob();
  delay(a);
}
void dropa(int a){
  verdea();
  azulb();
  rojob();
  delay(a);
  verdeb();
  azulb();
  rojoa();
  delay(a);
}
void loop(){
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(100);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(50);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  drop(25);
  dropa(1000);
}
