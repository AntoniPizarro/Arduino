#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>
#define YP A3
#define XM A2
#define YM 9
#define XP 8
#define TS_MINX 210
#define TS_MINY 210
#define TS_MAXX 810
#define TS_MAXY 815
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define BLACK     0x0000
#define BLUE      0x001F
#define GREY      0xCE79
#define LIGHTGREY 0xDEDB
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define MINPRESSURE 1
#define MAXPRESSURE 1000
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);
#define BOXSIZE 70
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
int X, Y, Z;
double tHeight = tft.height() - 1;
double center = (tft.width() / 2) - (BOXSIZE / 2);
double padding = 10;
double fromCenter = BOXSIZE + padding;
double secondRow = BOXSIZE + padding;
double thirdRow = secondRow + BOXSIZE + padding;
double fourthRow = thirdRow + BOXSIZE + padding;
double verticalAlign = (tHeight - ((BOXSIZE * 4) + (padding * 3))) / 2;
double leftColPositionX = center - fromCenter;
double midColPositionX = center;
double rightColPositionX = center + fromCenter;
void setup(){
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);
}
void temperatura(){
  tft.setTextColor(RED);
  tft.setCursor(30,20);
  tft.setTextSize(5);
  tft.print("37'C");
  tft.setCursor(30,100);
  tft.setTextSize(2);
  tft.print("Hace un calor");
  tft.setCursor(30,120);
  tft.print("de la hostia");
}
void retrieveTouch(){
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  X = tft.width() - map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
  Y = map(p.y, TS_MAXY, TS_MINY, 0, tft.height());
  Z = p.z;
}
void loop(){
  retrieveTouch();
  if(Z>MINPRESSURE && Z<MAXPRESSURE){
  }
  temperatura();
}
