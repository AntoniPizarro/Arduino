int a=0;
void setup(){
  pinMode(11, OUTPUT);
}
void loop(){
  for(a=0;a<=10;a++){
    analogWrite(11, a);
  }
}
