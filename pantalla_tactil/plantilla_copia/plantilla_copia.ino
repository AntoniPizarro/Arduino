#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>
#define YP A3
#define XM A2
#define YM 9
#define XP 8
#define TS_MINX 210
#define TS_MINY 210
#define TS_MAXX 915
#define TS_MAXY 910
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
float x,y,n,a,b,m;
void setup(){
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);
  ejes();
  num();
  tft.setRotation(3);
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
void ejes(){
  for(x=0;x<=32;x++){
    tft.drawFastVLine(x*10,0,320,LIGHTGREY);
    tft.drawFastHLine(0,x*10,320,LIGHTGREY);
  }
  tft.drawFastVLine(120,0,320,WHITE);
  tft.drawFastHLine(0,160,320,WHITE);
  tft.setRotation(3);
  tft.setCursor(0,120);
  tft.print("-x");
  tft.setCursor(160,0);
  tft.print("+y");
  tft.setCursor(305,120);
  tft.print("+x");
  tft.setCursor(160,230);
  tft.print("-y");
}
void fun(float m, float n){
  for (a=0;a<=320;a++){
    x=-a;
    b=-m*a;
    y=-m*x;
    tft.drawPixel(x+160,y+120-(n*10),BLUE);
    tft.drawPixel(a+160,b+120-(n*10),BLUE);
  }
}
void num(){
  tft.fillRect(20,20,30,30,YELLOW);
  tft.fillRect(20,70,30,30,YELLOW);
  tft.fillRect(20,120,30,30,YELLOW);
}
void loop(){
  retrieveTouch();
  if(Z>MINPRESSURE && Z<MAXPRESSURE){
    
  }
}
