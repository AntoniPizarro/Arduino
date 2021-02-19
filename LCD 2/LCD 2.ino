#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int b=1,a=10;
void setup(){
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  lcd.begin(16, 2); // Fijar el numero de caracteres y de filas
  lcd.print("     Bomba:"); // Enviar el mensaje
}
void parp(){
  digitalWrite(5,1);
  delay(50);
  digitalWrite(5,0);
  delay(50);
}
void loop(){
  lcd.setCursor(0, 8);
  lcd.print("       ");
  lcd.print(a);
  analogWrite(6,0);
  delay(970);
  analogWrite(6,20);
  a=a-b;
  if (a<=9&&a>0){
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("09");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("08");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("07");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("06");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("05");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("04");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("03");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("02");
    analogWrite(6,0);
    delay(970);
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("01");
    analogWrite(6,0);
    delay(970);
    a=0;
    analogWrite(6,20);
    delay(30);
    lcd.setCursor(0, 8);
    lcd.print("       ");
    lcd.print("00");
  }
  if (a==0){
    analogWrite(6,20);
    a=0;
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    parp();
    a=30;
  }
  delay(30);
}
