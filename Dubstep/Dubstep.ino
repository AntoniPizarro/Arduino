long distancia;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
long tiempo;
void setup(){
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  pinMode(13,OUTPUT);
  lcd.begin(16,2);
}
void loop(){
  digitalWrite(7,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(7, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(6, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  Serial.println("Distancia ");
  Serial.print(distancia);
  Serial.println(" cm");
  lcd.setCursor(0,0);
  lcd.print("Distancia (cm)");
  lcd.setCursor(0,1);
  lcd.print(distancia);
  delay(1000);
}
