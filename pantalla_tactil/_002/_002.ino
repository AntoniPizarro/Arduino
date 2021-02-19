#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <registers.h>
#include <stdint.h>
#include <TouchScreen.h>
#define YP A2
#define XM A3
#define YM 8
#define TS_MINX 116*2
#define TS_MAXX 890*2
#define TS_MINY 83*2
#define TS_MAXY 913*2
#define XP 9
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts=TouchScreen(XP, YP, XM, YM, 300);
void setup(void) {
  uint16_t identifier = tft.readID();
  identifier=0x9341;
  tft.begin(identifier);
  Serial.begin(9600);
}
void loop(void) {
  tft.fillScreen(BLACK);
  TSPoint p=ts.getPoint();
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 240);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 320);
  while (p.z>ts.pressureThreshhold) {
    tft.fillRect(40,30,60,30,RED);
  }
}
