#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
//#include <avr/power.h>

#include "U8glib.h"

#include <Encoder.h>     

const int CLK_TEMP = 23;      // Definition der Pins. CLK an D6, DT an D5. 
const int DT_TEMP = 25;
int SW_TEMP = 59;       
long oldPos_TEMP = -999;
bool en1 = false;

const int CLK_HUE = 27;      // Definition der Pins. CLK an D6, DT an D5. 
const int DT_HUE = 29;
int SW_HUE = 60;       
long oldPos_HUE = -999;  

bool en2 = false;

Bounce ENC_1 = Bounce(SW_TEMP, 10);
Bounce ENC_2 = Bounce(SW_HUE, 10);

Encoder EncoderTemp(DT_TEMP,CLK_TEMP);
Encoder EncoderHue(DT_HUE,CLK_HUE);  

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 

#define PIN  13
#define NUMPIXELS 100

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

long timer = 0;
bool timerCheck = true;
const long DISPLAY_DELAY = 1400;

//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(0, 1); // RX, TX

int red[3] = {0,255, 0};
int green[3] = {255, 0, 0};
int blue[3] = {0, 0, 255};
int orange[3] = {60, 255, 0};
int yellow[3] = {110, 140, 0};
int purple[3] = {0, 110, 200};
int white[3] = {255, 255, 255};
int colorSetLeft[][3] = {{230, 130, 0}, {0, 0, 0}, {0, 0, 150}, {0, 0, 90}, {0, 0, 50}, {0, 0, 10}, {90, 90, 90}, {90, 90, 90}, {30, 17, 0}, {100, 50, 0}, {150, 80, 0}, {180, 110, 0}};
int colorSetRight[][3] = {{100, 0, 200}, {0, 0, 0}, {0, 160, 0}, {0, 100, 0}, {0, 60, 0}, {0, 20, 0}, {90, 90, 90}, {90, 90, 90}, {6, 0, 10}, {10, 0, 18}, {30, 0, 56}, {120, 0, 200}};

void setTwelveButtonsColor(int rgb[]){
  for(int i = 0; i < 12; i++){
    pixels.setPixelColor(i, pixels.Color(rgb[0], rgb[1], rgb[2]));
    pixels.show();
  }
}
void setLeftColorWheel(int colors[][3]){
  int count = 0;
  for(int i = 22; i < 34; i++){
    pixels.setPixelColor(i, pixels.Color(colors[count][0], colors[count][1], colors[count][2]));
    pixels.show();
    count++;
  }
}

void setRightColorWheel(int colors[][3]){
  int count = 0;
  for(int i = 34; i < 46; i++){
    pixels.setPixelColor(i, pixels.Color(colors[count][0], colors[count][1], colors[count][2]));
    pixels.show();
    count++;
  }
}

void printHomeView(){
  u8g.setFont(u8g_font_courB08);
  u8g.drawStr( 25, 12, "System State:");
  u8g.setFont(u8g_font_courB18);
  u8g.drawStr( 0, 37, "Excellent");
  u8g.setFont(u8g_font_courB08);
  u8g.drawStr( 0, 57, "Battery Level:");
  u8g.drawStr( 95, 57, "4,2 V");
}

void buttonPress(char c){
  switch(c){
    case 'A':
      pixels.setPixelColor(0, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'B':
      pixels.setPixelColor(1, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'C':
      pixels.setPixelColor(2, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'D':
      pixels.setPixelColor(3, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'E':
      pixels.setPixelColor(4, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'F':
      pixels.setPixelColor(5, pixels.Color(red[0], red[1], red[2]));
      pixels.show();
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'G':
    pixels.setPixelColor(5, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
     setTwelveButtonsColor(white);
      break;
    case 'H':
    pixels.setPixelColor(0, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'I':
    pixels.setPixelColor(4, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'J':
    pixels.setPixelColor(1, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'K':
    pixels.setPixelColor(10, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'L':
    pixels.setPixelColor(2, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'M':
    pixels.setPixelColor(12, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;
    case 'N':
    pixels.setPixelColor(13, pixels.Color(red[0], red[1], red[2]));
    pixels.show();
     delay(200);
      setTwelveButtonsColor(white);
      break;                                                                        
  }
}

void EncoderClicks(){
  if(ENC_1.update()){
    if(!en1){
      Serial.write("CLICK!");
      en1 = true;
      u8g.firstPage();  
        do {
        printActionWithValue(0, "Temperatur", 2, true);
        } while( u8g.nextPage() );
      timerCheck = false;
      timer = millis(); 
    }
    else{
      en1 = false;
    }
  }
  if(ENC_2.update()){
    if(!en2){
      Serial.write("CLICK2!");
      en2 = true;
      u8g.firstPage();  
        do {
        printActionWithValue(0, "Toenung", 2, true);
        } while( u8g.nextPage() );
      timerCheck = false;
      timer = millis(); 
    }
    else{
      en2 = false;
    }
  }
}

void printActionWithValue(int val, char action[], int valLen, bool reset){
  u8g.setFont(u8g_font_courB12);
  u8g.drawStr( 0, 20, action);
  u8g.setFont(u8g_font_courB08);
  char c[valLen];
  String s = String(val);
  s.toCharArray(c, valLen);
  u8g.drawStr( 0, 57, c);
  if(reset){
    u8g.drawStr( 0, 40, "RESET");
  }
}

int getValLen(long val){
  if(val > 999){      
    return 5;
        }
  else if(val > 99){  
    return 4;
        }
  else if(val > 9){
    return 3;
        }
  else if(val < 0 && val >= -9){
    return -2;
    }
  else if(val < -9 && val >= -99){
    return -3;
  }
  else if(val < -99 && val >= -999){
    return -4;
  }
  else{
    return 2;
  }
}

void setup() {
  Serial.begin(9600);
  //Serial3.begin(9600);
  //SerialUSB.begin(9600);
  pinMode(SW_TEMP, INPUT); 
  pinMode(SW_HUE, INPUT);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  pixels.begin();
  setTwelveButtonsColor(white);
  int testColorSet[][3] = {{200, 140, 0}, {230, 130, 0}, {0, 0, 0}, {0, 0, 150}, {0, 0, 90}, {0, 0, 50}, {0, 0, 10}, {90, 90, 90}, {90, 90, 90}, {30, 17, 0}, {100, 50, 0}, {150, 80, 0}};
  setLeftColorWheel(colorSetLeft);
  setRightColorWheel(colorSetRight);
  timer = millis();
}

void loop() {
  char msg = ' ';
  if (Serial.available()){
     msg = Serial.read();
     Serial.println(msg);
  }
  if(timerCheck){
    u8g.firstPage();  
    do {
      printHomeView();
    } while( u8g.nextPage() );
  
  
  }
    EncoderClicks();
  buttonPress(msg);
  long newPos_TEMP = EncoderTemp.read(); 

        if (newPos_TEMP != oldPos_TEMP)  
        {
        oldPos_TEMP = newPos_TEMP;       
        Serial.println(newPos_TEMP); 
        int valLen = 2; 
        if(newPos_TEMP > 999){      
          valLen = 5;
        }
        else if(newPos_TEMP > 99){  
          valLen = 4;
        }
        else if(newPos_TEMP > 9){
          valLen = 3;
        }
        u8g.firstPage();  
        do {
        printActionWithValue(newPos_TEMP, "Temperatur", getValLen(newPos_TEMP), false);
        } while( u8g.nextPage() );
        timerCheck = false;
        timer = millis();     
        }
  long newPos_HUE = EncoderHue.read();   

        if (newPos_HUE != oldPos_HUE)  
        {
        oldPos_HUE = newPos_HUE;       
        Serial.println(newPos_HUE);
        u8g.firstPage();  
        //do {
        //printActionWithValue(newPos_HUE, "Toenung", getValLen(newPos_HUE), false);
        //} while( u8g.nextPage() );
        timerCheck = false;
        timer = millis();
        }
        if(millis() > (timer + DISPLAY_DELAY) && !timerCheck){
          timerCheck = true;
        }
}
  //
