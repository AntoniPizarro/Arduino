int a;
void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  a=analogRead(A0);
  Serial.println(a);
  if(a<20){
    digitalWrite(10,1);
    digitalWrite(11,0);
    digitalWrite(12,0);
  }
  if(a>20 && a<30){
    digitalWrite(10,0);
    digitalWrite(11,1);
    digitalWrite(12,0);
  }
  if(a>30){
    digitalWrite(10,0);
    digitalWrite(11,0);
    digitalWrite(12,1);
    bip(a);
  }
}
void bip(int a){
  digitalWrite(13,1);
  delay(50);
  digitalWrite(13,0);
  delay(200-a);
}

