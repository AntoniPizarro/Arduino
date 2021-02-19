#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
void setup(void) {
  uint16_t identifier = tft.readID();
  identifier=0x9341;
  tft.begin(identifier);
  tft.fillScreen(BLACK);
}
void loop(void) {
  tft.setCursor(0,0);
  tft.setTextColor(GREEN);
  tft.println("Granpepinillo Fullbit [Version 0.0.3]");
  tft.println("<c> 2017 Granpepinillo Corporation.");
  tft.println("Todos los derechos reservados");
  tft.println();
  tft.println("C:/User/Granpepinillo");
}
