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
int a,pos;
void setup(){
  a=0;
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);
  marco();
}
void conejitoa(){
  setup();
  tft.fillCircle(60,20,1,YELLOW);
  tft.fillCircle(63,20,1,YELLOW);
  tft.fillCircle(66,23,1,YELLOW);
  tft.fillCircle(57,23,1,YELLOW);
  tft.fillCircle(57,26,1,YELLOW);
  tft.fillCircle(57,29,1,YELLOW);
  tft.fillCircle(54,26,1,YELLOW);
  tft.fillCircle(51,23,1,YELLOW);
  tft.fillCircle(48,23,1,YELLOW);
  tft.fillCircle(45,26,1,YELLOW);
  tft.fillCircle(45,29,1,YELLOW);
  tft.fillCircle(45,32,1,YELLOW);
  tft.fillCircle(48,35,1,YELLOW);
  tft.fillCircle(51,38,1,YELLOW);
  tft.fillCircle(54,41,1,YELLOW);
  tft.fillCircle(57,41,1,YELLOW);
  tft.fillCircle(57,44,1,YELLOW);
  tft.fillCircle(54,47,1,YELLOW);
  tft.fillCircle(51,47,1,YELLOW);
  tft.fillCircle(48,47,1,YELLOW);
  tft.fillCircle(45,47,1,YELLOW);
  tft.fillCircle(42,47,1,YELLOW);
  tft.fillCircle(39,50,1,YELLOW);
  tft.fillCircle(36,50,1,YELLOW);
  tft.fillCircle(33,53,1,YELLOW);
  tft.fillCircle(30,56,1,YELLOW);
  tft.fillCircle(27,56,1,YELLOW);
  tft.fillCircle(24,59,1,YELLOW);
  tft.fillCircle(24,62,1,YELLOW);
  tft.fillCircle(27,65,1,YELLOW);
  tft.fillCircle(30,65,1,YELLOW);
  tft.fillCircle(30,62,1,YELLOW);
  tft.fillCircle(30,59,1,YELLOW);
  tft.fillCircle(30,68,1,YELLOW);
  tft.fillCircle(33,71,1,YELLOW);
  tft.fillCircle(36,74,1,YELLOW);
  tft.fillCircle(36,77,1,YELLOW);
  tft.fillCircle(39,80,1,YELLOW);
  tft.fillCircle(42,80,1,YELLOW);
  tft.fillCircle(45,80,1,YELLOW);
  tft.fillCircle(48,80,1,YELLOW);
  tft.fillCircle(51,80,1,YELLOW);
  tft.fillCircle(54,80,1,YELLOW);
  tft.fillCircle(57,80,1,YELLOW);
  tft.fillCircle(60,80,1,YELLOW);
  tft.fillCircle(63,80,1,YELLOW);
  tft.fillCircle(63,77,1,YELLOW);
  tft.fillCircle(60,74,1,YELLOW);
  tft.fillCircle(57,74,1,YELLOW);
  tft.fillCircle(54,74,1,YELLOW);
  tft.fillCircle(63,71,1,YELLOW);
  tft.fillCircle(66,71,1,YELLOW);
  tft.fillCircle(69,71,1,YELLOW);
  tft.fillCircle(72,71,1,YELLOW);
  tft.fillCircle(75,71,1,YELLOW);
  tft.fillCircle(75,68,1,YELLOW);
  tft.fillCircle(78,68,1,YELLOW);
  tft.fillCircle(81,68,1,YELLOW);
  tft.fillCircle(75,62,1,YELLOW);
  tft.fillCircle(75,59,1,YELLOW);
  tft.fillCircle(72,59,1,YELLOW);
  tft.fillCircle(78,56,1,YELLOW);
  tft.fillCircle(78,53,1,YELLOW);
  tft.fillCircle(78,50,1,YELLOW);
  tft.fillCircle(75,47,1,YELLOW);
  tft.fillCircle(72,44,1,YELLOW);
  tft.fillCircle(69,41,1,YELLOW);
  tft.fillCircle(69,38,1,YELLOW);
  tft.fillCircle(69,35,1,YELLOW);
  tft.fillCircle(69,32,1,YELLOW);
  tft.fillCircle(69,29,1,YELLOW);
  tft.fillCircle(69,26,1,YELLOW);
  tft.fillCircle(60,32,1,YELLOW);
  tft.fillCircle(63,35,1,YELLOW);
  tft.fillCircle(63,38,1,YELLOW);
  tft.fillCircle(66,50,1,YELLOW);
  tft.fillCircle(54,50,1,YELLOW);
  tft.fillCircle(54,53,1,YELLOW);
  tft.fillCircle(54,56,1,YELLOW);
  tft.fillCircle(57,59,1,YELLOW);
  tft.fillCircle(60,62,1,YELLOW);
  tft.fillCircle(63,62,1,YELLOW);
  tft.fillCircle(66,62,1,YELLOW);
  tft.fillCircle(69,62,1,YELLOW);
  tft.fillCircle(60,23,1,RED);
  tft.fillCircle(60,26,1,RED);
  tft.fillCircle(60,29,1,RED);
  tft.fillCircle(63,23,1,RED);
  tft.fillCircle(63,26,1,RED);
  tft.fillCircle(63,29,1,RED);
  tft.fillCircle(63,32,1,RED);
  tft.fillCircle(66,26,1,RED);
  tft.fillCircle(66,29,1,RED);
  tft.fillCircle(66,32,1,RED);
  tft.fillCircle(66,35,1,RED);
  tft.fillCircle(66,38,1,RED);
  tft.fillCircle(60,38,1,RED);
  tft.fillCircle(57,38,1,RED);
  tft.fillCircle(54,38,1,RED);
  tft.fillCircle(54,35,1,RED);
  tft.fillCircle(51,35,1,RED);
  tft.fillCircle(51,32,1,RED);
  tft.fillCircle(48,32,1,RED);
  tft.fillCircle(48,29,1,RED);
  tft.fillCircle(48,26,1,RED);
  tft.fillCircle(51,26,1,RED);
  tft.fillCircle(54,29,1,RED);
  tft.fillCircle(57,32,1,RED);
  tft.fillCircle(60,35,1,RED);
  tft.fillCircle(51,29,1,WHITE);
  tft.fillCircle(54,32,1,WHITE);
  tft.fillCircle(57,35,1,WHITE);
  tft.fillCircle(60,41,1,RED);
  tft.fillCircle(63,41,1,RED);
  tft.fillCircle(66,41,1,RED);
  tft.fillCircle(60,44,1,RED);
  tft.fillCircle(63,44,1,RED);
  tft.fillCircle(66,44,1,RED);
  tft.fillCircle(69,44,1,WHITE);
  tft.fillCircle(57,47,1,RED);
  tft.fillCircle(60,47,1,RED);
  tft.fillCircle(63,47,1,RED);
  tft.fillCircle(66,47,1,RED);
  tft.fillCircle(69,47,1,WHITE);
  tft.fillCircle(72,47,1,WHITE);
  tft.fillCircle(57,50,1,RED);
  tft.fillCircle(60,50,1,RED);
  tft.fillCircle(63,50,1,RED);
  tft.fillCircle(69,50,1,RED);
  tft.fillCircle(72,50,1,RED);
  tft.fillCircle(75,50,1,WHITE);
  tft.fillCircle(57,53,1,RED);
  tft.fillCircle(60,53,1,RED);
  tft.fillCircle(63,53,1,RED);
  tft.fillCircle(66,53,1,RED);
  tft.fillCircle(69,53,1,RED);
  tft.fillCircle(72,53,1,RED);
  tft.fillCircle(75,53,1,WHITE);
  tft.fillCircle(57,56,1,RED);
  tft.fillCircle(60,56,1,RED);
  tft.fillCircle(63,56,1,RED);
  tft.fillCircle(66,56,1,RED);
  tft.fillCircle(69,56,1,RED);
  tft.fillCircle(72,56,1,WHITE);
  tft.fillCircle(75,56,1,MAGENTA);
  tft.fillCircle(60,59,1,WHITE);
  tft.fillCircle(63,59,1,WHITE);
  tft.fillCircle(66,59,1,WHITE);
  tft.fillCircle(69,59,1,WHITE);
  tft.fillCircle(72,62,1,BLUE);
  tft.fillCircle(72,65,1,BLUE);
  tft.fillCircle(75,65,1,BLUE);
  tft.fillCircle(75,68,1,BLUE);
  tft.fillCircle(78,71,1,GREEN);
  tft.fillCircle(81,71,1,GREEN);
  tft.fillCircle(78,74,1,GREEN);
  tft.fillCircle(69,68,1,RED);
  tft.fillCircle(66,65,1,RED);
  tft.fillCircle(72,68,1,YELLOW);
  tft.fillCircle(69,65,1,YELLOW);
  tft.fillCircle(66,68,1,WHITE);
  tft.fillCircle(63,68,1,WHITE);
  tft.fillCircle(63,65,1,WHITE);
  tft.fillCircle(60,65,1,WHITE);
  tft.fillCircle(57,65,1,WHITE);
  tft.fillCircle(57,62,1,WHITE);
  tft.fillCircle(54,62,1,WHITE);
  tft.fillCircle(54,59,1,WHITE);
  tft.fillCircle(51,59,1,WHITE);
  tft.fillCircle(51,56,1,WHITE);
  tft.fillCircle(51,53,1,WHITE);
  tft.fillCircle(51,50,1,WHITE);
  tft.fillCircle(48,56,1,WHITE);
  tft.fillCircle(48,53,1,WHITE);
  tft.fillCircle(48,50,1,WHITE);
  tft.fillCircle(48,50,1,WHITE);
  tft.fillCircle(42,50,1,RED);
  tft.fillCircle(45,50,1,RED);
  tft.fillCircle(48,53,1,WHITE);
  tft.fillCircle(45,53,1,RED);
  tft.fillCircle(48,56,1,WHITE);
  tft.fillCircle(45,56,1,RED);
  tft.fillCircle(48,59,1,RED);
  tft.fillCircle(45,59,1,RED);
  tft.fillCircle(48,62,1,RED);
  tft.fillCircle(45,62,1,RED);
  tft.fillCircle(48,65,1,RED);
  tft.fillCircle(45,65,1,RED);
  tft.fillCircle(48,68,1,RED);
  tft.fillCircle(45,68,1,RED);
  tft.fillCircle(48,71,1,RED);
  tft.fillCircle(45,71,1,RED);
  tft.fillCircle(48,74,1,RED);
  tft.fillCircle(45,74,1,RED);
  tft.fillCircle(48,77,1,RED);
  tft.fillCircle(45,77,1,RED);
  tft.fillCircle(42,53,1,RED);
  tft.fillCircle(42,56,1,RED);
  tft.fillCircle(42,59,1,RED);
  tft.fillCircle(42,62,1,RED);
  tft.fillCircle(42,65,1,RED);
  tft.fillCircle(42,68,1,RED);
  tft.fillCircle(42,71,1,RED);
  tft.fillCircle(42,74,1,RED);
  tft.fillCircle(42,77,1,RED);
  tft.fillCircle(39,53,1,RED);
  tft.fillCircle(39,56,1,RED);
  tft.fillCircle(39,59,1,RED);
  tft.fillCircle(39,62,1,RED);
  tft.fillCircle(39,65,1,RED);
  tft.fillCircle(39,68,1,RED);
  tft.fillCircle(39,71,1,RED);
  tft.fillCircle(39,74,1,RED);
  tft.fillCircle(39,77,1,RED);
  tft.fillCircle(36,53,1,RED);
  tft.fillCircle(36,56,1,RED);
  tft.fillCircle(36,59,1,RED);
  tft.fillCircle(36,62,1,RED);
  tft.fillCircle(36,65,1,RED);
  tft.fillCircle(36,68,1,RED);
  tft.fillCircle(36,71,1,RED);
  tft.fillCircle(33,56,1,RED);
  tft.fillCircle(33,59,1,RED);
  tft.fillCircle(33,62,1,RED);
  tft.fillCircle(33,65,1,RED);
  tft.fillCircle(33,68,1,RED);
  tft.fillCircle(27,59,1,RED);
  tft.fillCircle(27,62,1,WHITE);
  tft.fillCircle(51,62,1,RED);
  tft.fillCircle(51,65,1,RED);
  tft.fillCircle(51,68,1,RED);
  tft.fillCircle(51,71,1,RED);
  tft.fillCircle(51,74,1,RED);
  tft.fillCircle(51,77,1,RED);
  tft.fillCircle(54,65,1,RED);
  tft.fillCircle(54,68,1,RED);
  tft.fillCircle(54,71,1,RED);
  tft.fillCircle(54,77,1,RED);
  tft.fillCircle(57,77,1,WHITE);
  tft.fillCircle(60,77,1,WHITE);
  tft.fillCircle(57,71,1,RED);
  tft.fillCircle(60,71,1,RED);
  tft.fillCircle(57,68,1,RED);
  tft.fillCircle(60,68,1,RED);
}
void corazon(int x, int y){
  tft.fillCircle(x,y,1,RED);
  tft.fillCircle(x+3,y,1,RED);
  tft.fillCircle(x,y+3,1,RED);
  tft.fillCircle(x+3,y+3,1,RED);
  tft.fillCircle(x+3,y+6,1,RED);
  tft.fillCircle(x+6,y+3,1,RED);
  tft.fillCircle(x+6,y+6,1,RED);
  tft.fillCircle(x+6,y+9,1,RED);
  tft.fillCircle(x+9,y,1,RED);
  tft.fillCircle(x+9,y+3,1,RED);
  tft.fillCircle(x+9,y+6,1,RED);
  tft.fillCircle(x+12,y,1,RED);
  tft.fillCircle(x+12,y+3,1,RED);
}
void conejitob(){
  setup();
  tft.fillCircle(100,20,1,GREY);
  tft.fillCircle(100,23,1,GREY);
  tft.fillCircle(100,26,1,GREY);
  tft.fillCircle(100,29,1,GREY);
  tft.fillCircle(100,35,1,GREY);
  tft.fillCircle(100,38,1,GREY);
  tft.fillCircle(100,41,1,GREY);
  tft.fillCircle(100,44,1,GREY);
  tft.fillCircle(100,47,1,GREY);
  tft.fillCircle(100,50,1,GREY);
  tft.fillCircle(100,53,1,GREY);
  tft.fillCircle(100,56,1,GREY);
  tft.fillCircle(100,59,1,GREY);
  tft.fillCircle(100,62,1,GREY);
  tft.fillCircle(100,65,1,GREY);
  tft.fillCircle(100,68,1,GREY);
  tft.fillCircle(100,71,1,GREY);
  tft.fillCircle(100,74,1,GREY);
  tft.fillCircle(103,23,1,GREY);
  tft.fillCircle(103,26,1,GREY);
  tft.fillCircle(103,29,1,GREY);
  tft.fillCircle(103,32,1,GREY);
  tft.fillCircle(103,35,1,GREY);
  tft.fillCircle(103,38,1,GREY);
  tft.fillCircle(103,41,1,GREY);
  tft.fillCircle(103,44,1,GREY);
  tft.fillCircle(103,47,1,GREY);
  tft.fillCircle(103,50,1,GREY);
  tft.fillCircle(103,56,1,GREY);
  tft.fillCircle(103,59,1,GREY);
  tft.fillCircle(103,62,1,GREY);
  tft.fillCircle(103,65,1,GREY);
  tft.fillCircle(103,68,1,GREY);
  tft.fillCircle(103,71,1,GREY);
  tft.fillCircle(103,74,1,GREY);
  tft.fillCircle(103,77,1,GREY);
  tft.fillCircle(106,29,1,MAGENTA);
  tft.fillCircle(106,32,1,MAGENTA);
  tft.fillCircle(106,35,1,MAGENTA);
  tft.fillCircle(106,38,1,MAGENTA);
  tft.fillCircle(106,41,1,GREY);
  tft.fillCircle(106,44,1,GREY);
  tft.fillCircle(106,47,1,GREY);
  tft.fillCircle(106,62,1,GREY);
  tft.fillCircle(106,65,1,GREY);
  tft.fillCircle(106,68,1,GREY);
  tft.fillCircle(106,71,1,GREY);
  tft.fillCircle(106,74,1,GREY);
  tft.fillCircle(106,77,1,GREY);
  tft.fillCircle(109,35,1,MAGENTA);
  tft.fillCircle(109,26,1,MAGENTA);
  tft.fillCircle(109,29,1,MAGENTA);
  tft.fillCircle(109,32,1,MAGENTA);
  tft.fillCircle(109,38,1,GREY);
  tft.fillCircle(112,23,1,GREY);
  tft.fillCircle(112,26,1,GREY);
  tft.fillCircle(112,29,1,GREY);
  tft.fillCircle(112,32,1,GREY);
  tft.fillCircle(112,35,1,GREY);
  tft.fillCircle(97,35,1,GREY);
  tft.fillCircle(97,38,1,GREY);
  tft.fillCircle(97,41,1,WHITE);
  tft.fillCircle(97,44,1,WHITE);
  tft.fillCircle(97,47,1,GREY);
  tft.fillCircle(97,50,1,GREY);
  tft.fillCircle(97,53,1,GREY);
  tft.fillCircle(97,56,1,WHITE);
  tft.fillCircle(97,59,1,GREY);
  tft.fillCircle(97,62,1,GREY);
  tft.fillCircle(97,65,1,WHITE);
  tft.fillCircle(97,68,1,WHITE);
  tft.fillCircle(97,77,1,WHITE);
  tft.fillCircle(97,80,1,WHITE);
  tft.fillCircle(100,77,1,WHITE);
  tft.fillCircle(100,80,1,WHITE);
  tft.fillCircle(94,77,1,WHITE);
  tft.fillCircle(94,80,1,WHITE);
  tft.fillCircle(103,80,1,WHITE);
  tft.fillCircle(106,80,1,WHITE);
  tft.fillCircle(109,80,1,GREY);
  tft.fillCircle(112,80,1,GREY);
  tft.fillCircle(115,80,1,GREY);
  tft.fillCircle(118,80,1,WHITE);
  tft.fillCircle(121,80,1,WHITE);
  tft.fillCircle(121,77,1,WHITE);
  tft.fillCircle(121,74,1,WHITE);
  tft.fillCircle(121,71,1,WHITE);
  tft.fillCircle(124,77,1,WHITE);
  tft.fillCircle(124,74,1,WHITE);
  tft.fillCircle(124,71,1,WHITE);
  tft.fillCircle(109,77,1,GREY);
  tft.fillCircle(112,77,1,GREY);
  tft.fillCircle(115,77,1,GREY);
  tft.fillCircle(109,74,1,GREY);
  tft.fillCircle(112,74,1,GREY);
  tft.fillCircle(115,74,1,GREY);
  tft.fillCircle(109,71,1,GREY);
  tft.fillCircle(112,71,1,GREY);
  tft.fillCircle(115,71,1,GREY);
  tft.fillCircle(109,68,1,GREY);
  tft.fillCircle(112,68,1,GREY);
  tft.fillCircle(115,68,1,GREY);
  tft.fillCircle(109,65,1,GREY);
  tft.fillCircle(112,65,1,GREY);
  tft.fillCircle(115,65,1,GREY);
  tft.fillCircle(109,62,1,GREY);
  tft.fillCircle(112,62,1,GREY);
  tft.fillCircle(115,62,1,GREY);
  tft.fillCircle(106,59,1,GREY);
  tft.fillCircle(109,59,1,GREY);
  tft.fillCircle(112,59,1,GREY);
  tft.fillCircle(118,65,1,GREY);
  tft.fillCircle(118,68,1,GREY);
  tft.fillCircle(118,71,1,GREY);
  tft.fillCircle(118,74,1,GREY);
  tft.fillCircle(118,77,1,GREY);
  tft.fillCircle(94,35,1,GREY);
  tft.fillCircle(94,38,1,GREY);
  tft.fillCircle(94,44,1,WHITE);
  tft.fillCircle(94,47,1,GREY);
  tft.fillCircle(94,50,1,GREY);
  tft.fillCircle(94,53,1,WHITE);
  tft.fillCircle(94,56,1,WHITE);
  tft.fillCircle(94,59,1,GREY);
  tft.fillCircle(94,62,1,GREY);
  tft.fillCircle(94,65,1,WHITE);
  tft.fillCircle(91,38,1,GREY);
  tft.fillCircle(91,41,1,GREY);
  tft.fillCircle(91,44,1,GREY);
  tft.fillCircle(91,47,1,WHITE);
  tft.fillCircle(91,50,1,WHITE);
  tft.fillCircle(88,41,1,MAGENTA);
  tft.fillCircle(88,44,1,WHITE);
  tft.fillCircle(88,47,1,WHITE);
  tft.fillCircle(88,50,1,WHITE);
  tft.fillCircle(85,41,1,MAGENTA);
  tft.fillCircle(85,44,1,MAGENTA);
  tft.fillCircle(85,47,1,WHITE);
  tft.fillCircle(91,59,1,GREY);
  tft.fillCircle(91,62,1,GREY);
  tft.fillCircle(91,65,1,GREY);
  tft.fillCircle(88,62,1,GREY);
  tft.fillCircle(88,65,1,WHITE);
  tft.fillCircle(88,68,1,WHITE);
  tft.fillCircle(85,65,1,WHITE);
  tft.fillCircle(85,68,1,WHITE);
}
void marco(){
  tft.drawRect(5,5,230,230,LIGHTGREY);
  tft.fillRect(10,250,30,30,WHITE);
  tft.fillRect(50,250,30,30,RED);
  tft.fillRect(90,250,30,30,BLUE);
  tft.fillRect(130,250,30,30,YELLOW);
  tft.fillRect(170,250,30,30,GREEN);
  tft.fillCircle(220,260,8,GREEN);
  tft.fillCircle(220,290,8,RED);
}
void paint(){
  if (a==1){
    tft.drawPixel(X,Y,WHITE);
  }
  if (a==2){
    tft.drawPixel(X,Y,RED);
  }
  if (a==3){
    tft.drawPixel(X,Y,BLUE);
  }
  if (a==4){
    tft.drawPixel(X,Y,GREEN);
  }
  if (a==5){
    tft.drawPixel(X,Y,YELLOW);
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
void loop(){
  retrieveTouch();
  if(Z>MINPRESSURE && Z<MAXPRESSURE){
    if(X>250 && X<270){
      if(Y>300 && Y<320){
        conejitoa();
      }
      if(Y>330 && Y<350){
        conejitob();
      }
    }
    Serial.print(X);
    Serial.print("---");
    Serial.println(Y);
    if(X>5 && X<234){
      if(Y>5 && Y<234){
        paint();
      }
    }
    if(X>(-20) && X<15){
      if(Y>300 && Y<330){
        a=1;
        tft.drawRect(9,249,32,32,MAGENTA);
        tft.drawRect(8,248,34,34,MAGENTA);
        tft.drawRect(49,249,32,32,BLACK);
        tft.drawRect(48,248,34,34,BLACK);
        tft.drawRect(89,249,32,32,BLACK);
        tft.drawRect(88,248,34,34,BLACK);
        tft.drawRect(129,249,32,32,BLACK);
        tft.drawRect(128,248,34,34,BLACK);
        tft.drawRect(169,249,32,32,BLACK);
        tft.drawRect(168,248,34,34,BLACK);
      }
    }
    if(X>30 && X<80){
      if(Y>300 && Y<330){
        a=2;
        tft.drawRect(9,249,32,32,BLACK);
        tft.drawRect(8,248,34,34,BLACK);
        tft.drawRect(49,249,32,32,MAGENTA);
        tft.drawRect(48,248,34,34,MAGENTA);
        tft.drawRect(89,249,32,32,BLACK);
        tft.drawRect(88,248,34,34,BLACK);
        tft.drawRect(129,249,32,32,BLACK);
        tft.drawRect(128,248,34,34,BLACK);
        tft.drawRect(169,249,32,32,BLACK);
        tft.drawRect(168,248,34,34,BLACK);
      }
    }
    if(X>90 && X<120){
      if(Y>300 && Y<330){
        a=3;
        tft.drawRect(9,249,32,32,BLACK);
        tft.drawRect(8,248,34,34,BLACK);
        tft.drawRect(49,249,32,32,BLACK);
        tft.drawRect(48,248,34,34,BLACK);
        tft.drawRect(89,249,32,32,MAGENTA);
        tft.drawRect(88,248,34,34,MAGENTA);
        tft.drawRect(129,249,32,32,BLACK);
        tft.drawRect(128,248,34,34,BLACK);
        tft.drawRect(169,249,32,32,BLACK);
        tft.drawRect(168,248,34,34,BLACK);
      }
    }
    if(X>190 && X<230){
      if(Y>300 && Y<330){
        a=4;
        tft.drawRect(9,249,32,32,BLACK);
        tft.drawRect(8,248,34,34,BLACK);
        tft.drawRect(49,249,32,32,BLACK);
        tft.drawRect(48,248,34,34,BLACK);
        tft.drawRect(89,249,32,32,BLACK);
        tft.drawRect(88,248,34,34,BLACK);
        tft.drawRect(129,249,32,32,BLACK);
        tft.drawRect(128,248,34,34,BLACK);
        tft.drawRect(169,249,32,32,MAGENTA);
        tft.drawRect(168,248,34,34,MAGENTA);
      }
    }
    if(X>140 && X<170){
      if(Y>300 && Y<330){
        a=5;
        tft.drawRect(9,249,32,32,BLACK);
        tft.drawRect(8,248,34,34,BLACK);
        tft.drawRect(49,249,32,32,BLACK);
        tft.drawRect(48,248,34,34,BLACK);
        tft.drawRect(89,249,32,32,BLACK);
        tft.drawRect(88,248,34,34,BLACK);
        tft.drawRect(129,249,32,32,MAGENTA);
        tft.drawRect(128,248,34,34,MAGENTA);
        tft.drawRect(169,249,32,32,BLACK);
        tft.drawRect(168,248,34,34,BLACK);
      }
    }
  }
}
