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

//Size of key containers 70px
#define BOXSIZE 70

//2.4 = 240 x 320
//Height 319 to fit on screen

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//Container variables for touch coordinates
int X, Y, Z;

//Screen height without hidden pixel
double tHeight = tft.height() - 1;
//Centering the mid square
double center = (tft.width() / 2) - (BOXSIZE / 2);
//Space between squares
double padding = 10;
//Position of squares to the left and right of center
double fromCenter = BOXSIZE + padding;
//Second row Y-Axis position
double secondRow = BOXSIZE + padding;
//Third row Y-Axis position
double thirdRow = secondRow + BOXSIZE + padding;
//Fourth row Y-Axis position
double fourthRow = thirdRow + BOXSIZE + padding;
//Y-Axis align for all squares
double verticalAlign = (tHeight - ((BOXSIZE * 4) + (padding * 3))) / 2;
//Left column starting x posision
double leftColPositionX = center - fromCenter;
//Mid column starting x posision
double midColPositionX = center;
//Right column starting x posision
double rightColPositionX = center + fromCenter;

int turn,a,b,c,d,e,f,g,h,i,part,j,aa,ab,ac,ba,bb,bc,ca,cb,cc;
void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(LIGHTGREY);
  Serial.println(F("Press any button on the TFT screen: "));
  tft.fillScreen(BLACK);  
  tft.fillRect(10,10,60,60,YELLOW);
  tft.fillRect(13,13,54,54,BLACK);
  tft.fillRect(80,10,60,60,YELLOW);
  tft.fillRect(83,13,54,54,BLACK);
  tft.fillRect(150,10,60,60,YELLOW);
  tft.fillRect(153,13,54,54,BLACK);
  tft.fillRect(10,80,60,60,YELLOW);
  tft.fillRect(13,83,54,54,BLACK);
  tft.fillRect(80,80,60,60,YELLOW);
  tft.fillRect(83,83,54,54,BLACK);
  tft.fillRect(150,80,60,60,YELLOW);
  tft.fillRect(153,83,54,54,BLACK);
  tft.fillRect(10,150,60,60,YELLOW);
  tft.fillRect(13,153,54,54,BLACK);
  tft.fillRect(80,150,60,60,YELLOW);
  tft.fillRect(83,153,54,54,BLACK);
  tft.fillRect(150,150,60,60,YELLOW);
  tft.fillRect(153,153,54,54,BLACK);
  tft.setCursor(20,250);
  tft.setTextSize(2);
  tft.print("Jugador");
  tft.setTextColor(WHITE);
  turn=1;
  a=0;
  b=0;
  c=0;
  d=0;
  e=0;
  f=0;
  g=0;
  h=0;
  i=0;
  j=6;
  part=0;
  aa=0;
  ab=0;
  ac=0;
  ba=0;
  bb=0;
  bc=0;
  ca=0;
  cb=0;
  cc=0;
}
void equis(int x,int y){
  tft.setCursor(x,y);
  tft.setTextSize(4);
  tft.print("X");
}
void circ(int x,int y){
  tft.setCursor(x,y);
  tft.setTextSize(4);
  tft.print("O");
}
void retrieveTouch(){
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  //If sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  //Scale from 0->1023 to tft.width
    //X = map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
  //  Y = map(p.y, TS_MAXY, TS_MINY, 0, tft.height());

  // on my tft the numbers are reversed so this is used instead of the above
  X = tft.width() - map(p.x, TS_MAXX, TS_MINX, 0, tft.width());
  Y = map(p.y, TS_MAXY, TS_MINY, 0, tft.height());
  Z = p.z;
}
void fin(int j){
  j--;
  tft.setTextSize(3);
  tft.setTextColor(YELLOW);
  tft.fillRect(150,210,30,50,BLACK);
  tft.setCursor(40,220);
  tft.print("Espere  s");
  tft.setCursor(160,220);
  tft.print(j);
  delay(1000);
  if(j==0){
    part=0;
    setup();
  }
  if(j>0){
    fin(j);
  }
}
void ja(){
  tft.setTextColor(RED);
  retrieveTouch();
  if(turn==1){
    tft.fillRect(110,230,50,50,BLACK);
    tft.setCursor(120,250);
    tft.setTextSize(3);
    tft.print(turn);
    if(Z>MINPRESSURE && Z<MAXPRESSURE){
      if(X>10 && X<70){
        if(Y>10 && Y<70){
          if(a==0){
            equis(30,30);
            turn=2;
            a++;
            aa=1;
            part++;
            delay(500);
          }
        }
        if(Y>80 && Y<150){
          if(d==0){
            equis(30,100);
            turn=2;
            d++;
            ba=1;
            part++;
            delay(500);
          }
       }
        if(Y>150 && Y<220){
          if(g==0){
            equis(30,170);
            turn=2;
            g++;
            ca=1;
            part++;
            delay(500);
          }
       }
     }
     if(X>80 && X<150){
       if(Y>10 && Y<70){
          if(b==0){
            equis(100,30);
            turn=2;
            b++;
            ab=1;
            part++;
            delay(500);
          }
        }
        if(Y>80 && Y<150){
          if(e==0){
            equis(100,100);
            turn=2;
            e++;
            bb=1;
            part++;
            delay(500);
          }
       }
       if(Y>150 && Y<220){
          if(h==0){
            equis(100,170);
            turn=2;
            h++;
            cb=1;
            part++;
            delay(500);
          }
        }
     }
     if(X>150 && X<220){
       if(Y>10 && Y<70){
          if(c==0){
            equis(170,30);
            turn=2;
            c++;
            ac=1;
            part++;
            delay(500);
          }
       }
       if(Y>80 && Y<150){
          if(f==0){
            equis(170,100);
            turn=2;
            f++;
            bc=1;
            part++;
            delay(500);
          }
        }
       if(Y>150 && Y<220){
          if(i==0){
            equis(170,170);
            turn=2;
            i++;
            cc=1;
            part++;
            delay(500);
          }
        }
      }
    }
  }
  if(aa==1){
      if(ab==1){
        if(ac==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
      if(ba==1){
        if(ca==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
      if(bb==1){
        if(cc==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
    }
    if(ab==1){
      if(bb==1){
        if(cb==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
    }
    if(ac==1){
      if(bc==1){
        if(cc==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
      if(bb==1){
        if(ca==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
    }
    if(bb==1){
      if(ba==1){
        if(bc==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
    }
    if(ca==1){
      if(cb==1){
        if(cc==1){
          tft.fillRect(10,100,220,80,RED);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 1");
          fin(j);
        }
      }
    }
  if(part==9){
    fin(j);
  }
  X=500;
  Y=500;
}
void jb(){
  tft.setTextColor(BLUE);
  retrieveTouch();
  if(turn==2){
    tft.fillRect(110,230,50,50,BLACK);
    tft.setCursor(120,250);
    tft.setTextSize(3);
    tft.print(turn);
    if(Z>MINPRESSURE && Z<MAXPRESSURE){
      if(X>10 && X<70){
        if(Y>10 && Y<70){
          if(a==0){
            circ(30,30);
            turn=1;
            a++;
            aa=2;
            part++;
            delay(500);
          }
        }
        if(Y>80 && Y<150){
          if(d==0){
            circ(30,100);
            turn=1;
            d++;
            ba=2;
            part++;
            delay(500);
          }
       }
        if(Y>150 && Y<220){
          if(g==0){
            circ(30,170);
            turn=1;
            g++;
            ca=2;
            part++;
            delay(500);
          }
       }
     }
     if(X>80 && X<150){
       if(Y>10 && Y<70){
          if(b==0){
            circ(100,30);
            turn=1;
            b++;
            ab=2;
            part++;
            delay(500);
          }
        }
        if(Y>80 && Y<150){
          if(e==0){
            circ(100,100);
            turn=1;
            e++;
            bb=2;
            part++;
            delay(500);
          }
       }
       if(Y>150 && Y<220){
          if(h==0){
            circ(100,170);
            turn=1;
            h++;
            cb=2;
            part++;
            delay(500);
          }
        }
     }
     if(X>150 && X<220){
       if(Y>10 && Y<70){
          if(c==0){
            circ(170,30);
            turn=1;
            c++;
            ac=2;
            part++;
            delay(500);
          }
       }
       if(Y>80 && Y<150){
          if(f==0){
            circ(170,100);
            turn=1;
            f++;
            bc=2;
            part++;
            delay(500);
          }
        }
       if(Y>150 && Y<220){
          if(i==0){
            circ(170,170);
            turn=1;
            i++;
            cc=2;
            part++;
            delay(500);
          }
        }
      }
    }
    if(aa==2){
      if(ab==2){
        if(ac==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
      if(ba==2){
        if(ca==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
      if(bb==2){
        if(cc==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
    }
    if(ab==2){
      if(bb==2){
        if(cb==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
    }
    if(ac==2){
      if(bc==2){
        if(cc==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
      if(bb==2){
        if(ca==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
    }
    if(bb==2){
      if(ba==2){
        if(bc==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
    }
    if(ca==2){
      if(cb==2){
        if(cc==2){
          tft.fillRect(10,100,220,80,BLUE);
          tft.setCursor(20,125);
          tft.setTextSize(2);
          tft.setTextColor(WHITE);
          tft.print("Gana jugador 2");
          fin(j);
        }
      }
    }
  }
  if(part==9){
    fin(j);
  }
  X=500;
  Y=500;
}
void loop(){
  ja();
  jb();
}
