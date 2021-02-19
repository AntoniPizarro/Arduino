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



// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
// Pins A2-A6
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

//Size of key containers 70px
#define BOXSIZE 70

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
int X, Y, Z;
int accion,color=0;
long colorc=WHITE;
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
void intro(){
  tft.fillScreen(BLACK);
  delay(500);
  tft.setCursor(50,100);
  tft.setTextSize(3);
  delay(500);
  tft.setRotation(1);
  tft.setTextColor(RED);
  tft.print("Granpepinillo");
  tft.setRotation(0);
  delay(4000);
  tft.fillScreen(BLACK);
}
void iconcarp(int X,int Y){
  tft.fillRoundRect(X,Y,50,50,5,YELLOW);
  tft.drawRoundRect(X,Y,50,50,5,LIGHTGREY);
  tft.drawFastHLine(X+1,Y+18,48,LIGHTGREY);
  tft.fillRect(X+3,Y+3,44,14,WHITE);
  tft.fillCircle(X+40,Y+40,1,GREY);
  tft.fillCircle(X+30,Y+40,1,GREY);
  tft.fillCircle(X+35,Y+40,1,GREY);
  tft.fillRect(X+22,Y+19,6,10,GREY);
  tft.fillRect(X+30,Y+6,8,11,RED);
}
void iconpaint(int X,int Y){
  tft.drawRoundRect(X,Y,50,50,5,LIGHTGREY);
  tft.fillRoundRect(X+16,Y,12,29,3,RED);
  tft.fillTriangle(X+17,Y+31,X+25,Y+31,X+16,Y+42,GREEN);
  tft.fillCircle(X+40,Y+40,5,GREEN);
  tft.fillCircle(X+30,Y+40,5,BLUE);
  tft.fillCircle(X+35,Y+30,5,RED);
}
void paint(){
  tft.drawFastHLine(15,15,210,GREY);
  tft.drawFastVLine(15,15,210,GREY);
  tft.drawFastVLine(225,15,210,GREY);
  tft.drawFastHLine(15,225,210,GREY);
  tft.fillRoundRect(25,230,30,30,3,RED);
  tft.fillRoundRect(65,230,30,30,3,BLUE);
  tft.fillRoundRect(105,230,30,30,3,GREEN);
  tft.fillRoundRect(145,230,30,30,3,YELLOW);
  tft.fillRoundRect(185,230,30,30,3,WHITE);
  tft.fillRoundRect(225,0,15,15,2,RED);
  tft.setCursor(228,-2);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("x");
}
void escritorio(){
  iconcarp(15,15);
  iconpaint(80,15);
}
void pintar(){
  retrieveTouch();
  if(X>25 && X<55 && Y>230 && Y<250){
    colorc=RED;
  }
  if(X>65 && X<95 && Y>230 && Y<250){
    colorc=BLUE;
  }
  if(X>105 && X<135 && Y>230 && Y<250){
    colorc=GREEN;
  }
  if(X>145 && X<175 && Y>230 && Y<250){
    colorc=YELLOW;
  }
  if(X>185 && X<215 && Y>230 && Y<250){
    colorc=WHITE;
  }
  if(X<225 && X>15 && Y<225 && Y>15){
    tft.drawPixel(X,Y,colorc);
  }
  if(X>225 && Y<15){
    accion=0;
  }
}
void setup(){
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  delay(1000);
  intro();
  tft.fillScreen(BLACK);
  escritorio();
}
void loop(){
  retrieveTouch();
  if (Z > MINPRESSURE && Z < MAXPRESSURE) {
    tft.drawPixel(X,Y,WHITE);
    if(X<65 && X>15 && Y<65 && Y>15){
      accion=1;
    }
    if(X<115 && X>65 && Y<65 && Y>15){
      accion=2;
    }
  }
  if(accion==0){
    tft.fillScreen(BLACK);
    escritorio();
    accion=3;
  }
  if(accion==2){
    tft.fillScreen(BLACK);
    paint();
    accion=4;
  }
  if(accion==4){
    pintar();
  }
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
