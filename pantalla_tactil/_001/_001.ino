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
void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  paint();
}
char color=WHITE;
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
void paint(){
  tft.fillScreen(BLACK);
  tft.fillRect(5,5,230,230,GREEN);
  tft.fillRect(10,10,220,220,BLACK);
  tft.fillRoundRect(10,240,30,30,5,WHITE);
  tft.fillRoundRect(50,240,30,30,5,RED);
  tft.fillRoundRect(90,240,30,30,5,BLUE);
  tft.fillRoundRect(130,240,30,30,5,GREEN);
  tft.fillRoundRect(170,240,30,30,5,YELLOW);
}
void loop(){
  retrieveTouch();
  if(Z>MINPRESSURE && Z<MAXPRESSURE){
    if(X>10 && X<230){
      if(Y>10 && Y<230){
        tft.drawPixel(X,Y,color);
        tft.drawPixel(X-1,Y,color);
        tft.drawPixel(X,Y-1,color);
        tft.drawPixel(X,Y+1,color);
        tft.drawPixel(X+1,Y,color);
      }
    }
    if(X>10 && X<40){
      if(Y>240 && Y<260){
        color=WHITE;
      }
    }
    if(X>50 && X<80){
      if(Y>240 && Y<260){
        color=RED;
      }
    }
    if(X>90 && X<120){
      if(Y>240 && Y<260){
        color=BLUE;
      }
    }
    if(X>130 && X<160){
      if(Y>240 && Y<260){
        color=GREEN;
      }
    }
    if(X>170 && X<200){
      if(Y>240 && Y<260){
        color=YELLOW;
      }
    }
  }
}
