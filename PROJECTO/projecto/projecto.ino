long distancia;
long tiempo;
int Paso [ 8 ][ 4 ] ={
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
int steps_left=4095;
boolean Direction = true;
int Steps = 0;
void setup(){
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, INPUT);
}
void stepper()            //Avanza un paso
   {  digitalWrite( 11, Paso[Steps][ 0] );
      digitalWrite( 10, Paso[Steps][ 1] );
      digitalWrite( 9, Paso[Steps][ 2] );
      digitalWrite( 8, Paso[Steps][ 3] );

      SetDirection();
}
void SetDirection()
   {  
      if(Direction)
         Steps++;
      else
         Steps--;

      Steps = ( Steps + 8 ) % 8 ;
}
void loop(){
  digitalWrite(12,LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  tiempo=pulseIn(13, HIGH);
  distancia= int(0.017*tiempo);
  Serial.println("Distancia ");
  Serial.println(distancia);
  Serial.println(" cm");
  delay(100);
  while(steps_left>0)
        { 
           stepper() ;     // Avanza un paso
           steps_left-- ;  // Un paso menos
           delay (1) ;
        }
     delay(300);
     Direction =! Direction;  // Invertimos la direceccion de giro
     steps_left = 4095;
}
