#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);
int a,b,c,d;
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A3,OUTPUT);
}
void uno(){
  digitalWrite(13,1);
  digitalWrite(6,0);
  digitalWrite(5,0);
  digitalWrite(4,0);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,0);
}
void dos(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,0);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,1);
  digitalWrite(A4,0);
  digitalWrite(A3,1);
}
void tres(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,0);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void cuatro(){
  digitalWrite(13,1);
  digitalWrite(6,0);
  digitalWrite(5,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,0);
}
void cinco(){
  digitalWrite(13,0);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void seis(){
  digitalWrite(13,0);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,1);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void siete(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,0);
  digitalWrite(4,0);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,0);
}
void ocho(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,1);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void cero(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(4,0);
  digitalWrite(3,0);
  digitalWrite(2,1);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void nueve(){
  digitalWrite(13,1);
  digitalWrite(6,1);
  digitalWrite(5,1);
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  digitalWrite(A4,1);
  digitalWrite(A3,1);
}
void loop(){
  c=analogRead(A0);
  b=analogRead(A1);
  a=analogRead(A2);
  lcd.clear();
  lcd.setCursor(0,0);
  if(b>100){
    d++;
  }
  if(a>100){
    d--;
  }
  if(c>100){
    d=0;
  }
  if(d==0){
    cero();
  }
  if(d==1){
    uno();
  }
  if(d==2){
    dos();
  }
  if(d==3){
    tres();
  }
  if(d==4){
    cuatro();
  }
  if(d==5){
    cinco();
  }
  if(d==6){
    seis();
  }
  if(d==7){
    siete();
  }
  if(d==8){
    ocho();
  }
  if(d==9){
    nueve();
  }
  if(d==10){
    d=0;
  }
  lcd.print("  *    *    *");
  lcd.setCursor(0,1);
  lcd.print("  -    +   res");
  delay(200);
}
