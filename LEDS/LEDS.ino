void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}
void aaa(){
  digitalWrite(2,1);
  digitalWrite(10,1);
}
void aab(){
  digitalWrite(2,0);
  digitalWrite(10,0);
}
void aba(){
  digitalWrite(3,1);
  digitalWrite(9,1);
}
void abb(){
  digitalWrite(3,0);
  digitalWrite(9,0);
}
void aca(){
  digitalWrite(4,1);
  digitalWrite(8,1);
}
void acb(){
  digitalWrite(4,0);
  digitalWrite(8,0);
}
void ada(){
  digitalWrite(5,1);
  digitalWrite(7,1);
}
void adb(){
  digitalWrite(5,0);
  digitalWrite(7,0);
}
void aea(){
  digitalWrite(6,1);
}
void aeb(){
  digitalWrite(6,0);
}
void late(){
  aaa();
  delay(50);
  aab();
  delay(50);
}
void azul(){
  aba();
  delay(50);
  abb();
  delay(50);
}
void rojo(){
  aca();
  delay(50);
  acb();
  delay(50);
}
void verde(){
  ada();
  delay(50);
  adb();
  delay(50);
}
void cent(){
  aea();
  delay(50);
  aeb();
  delay(50);
}
void loop() {
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(750);
  azul();
  delay(375);
  verde();
  delay(375);
  azul();
  delay(750);
  aba();
  delay(750);
}
