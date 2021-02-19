void setup() {
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
}
int a;
void loop() {
  for(a=0;a<=255;a++){
    analogWrite(A2, a);
    delay(100);
    Serial.print(a);
  }
  a=0;
}
