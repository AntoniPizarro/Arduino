void setup() {
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
int a;
void loop() {
  a=analogRead(A0);
  if (a>0){
    digitalWrite(9,1);
  }else{
    digitalWrite(9,0);
  }
  Serial.println(a);
}
