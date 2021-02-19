#include <Adafruit_GFX.h>
#include <TouchScreen.h>
#include <Adafruit_TFTLCD.h>
#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
// calibration mins and max for raw data when touching edges of screen
// YOU CAN USE THIS SKETCH TO DETERMINE THE RAW X AND Y OF THE EDGES TO GET YOUR HIGHS AND LOWS FOR X AND Y
#define TS_MINX 210
#define TS_MINY 210
#define TS_MAXX 915
#define TS_MAXY 910
//SPI Communication
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4
//Color Definitons
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
double padding = 10;//Position of squares to the left and right of center
double fromCenter = BOXSIZE + padding;
double secondRow = BOXSIZE + padding;
double thirdRow = secondRow + BOXSIZE + padding;
double fourthRow = thirdRow + BOXSIZE + padding;
double verticalAlign = (tHeight - ((BOXSIZE * 4) + (padding * 3))) / 2;
double leftColPositionX = center - fromCenter;
double midColPositionX = center;
double rightColPositionX = center + fromCenter;
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
int a,b,x,y,c,d;
void setup(){
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  tft.setCursor(0,0);
  for(a=0;a<=32;a++){
    b=a*10;
    tft.drawFastVLine(b,0,240,GREY);
  }
  for(a=0;a<=24;a++){
    b=a*10;
    tft.drawFastHLine(0,b,320,GREY);
  }
  tft.setRotation(0);
  fun();
}
void fun(){
  for(a=0;a<=32;a++){
    y=a*10;
    x=a*a;
    b=a+2;
    c=b*10;
    d=b*b;
    tft.drawLine(y,x,c,d,BLUE);
    tft.fillRect(209,10,31,40,BLACK);
    tft.setRotation(1);
    tft.setCursor(0,0);
    tft.print("y=");
    tft.println(y);
    tft.print("x=");
    tft.println(x);
    tft.print("c=");
    tft.println(c);
    tft.print("d=");
    tft.println(d);
    tft.println();
    tft.println("tft.drawLine(y,x,c,d,BLUE)");
    tft.print("YxY=X");
    tft.setRotation(0);
    delay(100);
  }
}
void loop(){
  retrieveTouch();
  if (Z > MINPRESSURE && Z < MAXPRESSURE){
    
  }
}
