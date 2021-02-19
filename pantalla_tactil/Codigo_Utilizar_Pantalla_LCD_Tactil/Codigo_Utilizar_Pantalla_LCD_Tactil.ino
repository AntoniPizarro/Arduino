#include <UTouch.h>
#include <UTouchCD.h>
#include <UTFT.h>


UTFT lcd(ILI9486,38,39,40,41);
UTouch tactil( 6, 5, 4, 3, 2);

extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t SevenSegNumFont[];

int pantalla;


void setup()
{
 lcd.InitLCD();
 lcd.clrScr();
 tactil.InitTouch();
 tactil.setPrecision(PREC_HI);
 pantalla = 1;
}


void loop()
{
  
  //-----------------------------Pantallas-------------------------------
  if(pantalla == 1)
  {
  lcd.setFont(BigFont);
  lcd.setColor(VGA_RED);
  lcd.print("ESTA ES LA PANTALLA", CENTER, 75);
  lcd.drawLine(0,166,479,166);//LINEA FIN SALIR
  lcd.print("TOCA AQUI PARA LA PANTALLA 2", CENTER, 240);
  }
  
  
  if(pantalla == 2)
  {
    lcd.print("Pantalla 2", CENTER, 75);
    lcd.drawLine(0,166,479,166);//LINEA FIN SALIR
    lcd.print("SALIR A PANTALLA 1", CENTER, 240);
  }
  //....................................................................



   
  
  //-------------------------Tactil P1------------------------------------
  if(pantalla == 1)
  {
    while(tactil.dataAvailable() == HIGH)
    {
      tactil.read();
      lcd.printNumI(tactil.getX(), CENTER, 100);
      lcd.printNumI(tactil.getY(), CENTER, 150);
      
      if(tactil.getX() < 160)
      {
        pantalla = 2;
        lcd.fillScr(VGA_BLACK);
        delay(250);
      }
      
      
    }
  }
  
  //...................................................................
  


 //-------------------Tactil P2---------------------------------------
 if(pantalla == 2)
 {
   while(tactil.dataAvailable() == HIGH)
   {
     tactil.read();
     lcd.printNumI(tactil.getX(), CENTER, 100);
     lcd.printNumI(tactil.getY(), CENTER, 150);
     
     if(tactil.getX() < 160)
     {
       pantalla = 1;
       lcd.fillScr(VGA_BLACK);
       delay(250);
     } 
     
     
   }
 }
 //................................................................... 
  
  
  
  
  
}
