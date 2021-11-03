#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
#include <Encoder.h>  
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//SoftwareSerial mySerial(A8, A9); // RX, TX


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String msgString = "";

bool displayCheck = false;

long timer;
//All clickable Encoders

//Temperatur
const int CLK_TEMP = 6;      
const int DT_TEMP = 5;
int SW_TEMP = 4;       
long oldPos_TEMP = -999;
bool enTEMP = false;
Bounce ENC_TEMP = Bounce(SW_TEMP, 10);
Encoder EncoderTEMP(DT_TEMP,CLK_TEMP);
int encoderValueTEMP;

//Hue
const int CLK_HUE = 10;      
const int DT_HUE = 9;
int SW_HUE = A2;       
long oldPos_HUE = -999;
bool enHUE = false;
Bounce ENC_HUE = Bounce(SW_HUE, 10);
Encoder EncoderHUE(DT_HUE,CLK_HUE);
int encoderValueHUE;

//Belichtung
const int CLK_BEL = 12;    
const int DT_BEL = 11;
int SW_BEL = A1;       
long oldPos_BEL = -999;
bool enBEL = false;
Bounce ENC_BEL = Bounce(SW_BEL, 10);
Encoder EncoderBEL(DT_BEL,CLK_BEL);
int encoderValueBEL;

//Kontrast
const int CLK_KON = 23;      
const int DT_KON = 25;
int SW_KON = A5;       
long oldPos_KON = -999;
bool enKON = false;
Bounce ENC_KON = Bounce(SW_KON, 10);
Encoder EncoderKON(DT_KON,CLK_KON);
int encoderValueKON;

//Lichter
const int CLK_LI = 31;      
const int DT_LI = 33;
int SW_LI = A7;       
long oldPos_LI = -999;
bool enLI = false;
Bounce ENC_LI = Bounce(SW_LI, 10);
Encoder EncoderLI(DT_LI,CLK_LI);
int encoderValueLI;

//Tiefen
const int CLK_TI = 39;      
const int DT_TI = 41;
int SW_TI = A10;       
long oldPos_TI = -999;
bool enTI = false;
Bounce ENC_TI = Bounce(SW_TI, 10);
Encoder EncoderTI(DT_TI,CLK_TI);
int encoderValueTI;

//Weiß
const int CLK_WE = A8;      
const int DT_WE = A9;
int SW_WE = A4;       
long oldPos_WE = -999;
bool enWE = false;
Bounce ENC_WE = Bounce(SW_WE, 10);
Encoder EncoderWE(DT_WE,CLK_WE);
int encoderValueWE;

//Schwarz
const int CLK_SW = 43;      
const int DT_SW = 45;
int SW_SW = A15;       
long oldPos_SW = -999;
bool enSW = false;
Bounce ENC_SW = Bounce(SW_SW, 10);
Encoder EncoderSW(DT_SW,CLK_SW);
int encoderValueSW;

//System1
const int CLK_S1 = 3;     
const int DT_S1 = 2; 
int SW_S1 = A3;      
long oldPos_S1 = -999;
bool enS1 = false;
Bounce ENC_S1 = Bounce(SW_S1, 10);
Encoder EncoderS1(DT_S1,CLK_S1);
int encoderValueS1;

//System2
const int CLK_S2 = 50;      
const int DT_S2 = 52;
int SW_S2 = A13;       
long oldPos_S2 = -999;
bool enS2 = false;
Bounce ENC_S2 = Bounce(SW_S2, 10);
Encoder EncoderS2(DT_S2,CLK_S2);
int encoderValueS2;

//Struktur
const int CLK_ST = 46;      
const int DT_ST = 48;
int SW_ST = A0;       
long oldPos_ST = -999;
bool enST = false;
Bounce ENC_ST = Bounce(SW_ST, 10);
Encoder EncoderST(DT_ST,CLK_ST);
int encoderValueST;

//Klarheit
const int CLK_KL = 47;      
const int DT_KL = 49;
int SW_KL = A14;       
long oldPos_KL = -999;
bool enKL = false;
Bounce ENC_KL = Bounce(SW_KL, 10);
Encoder EncoderKL(DT_KL,CLK_KL);
int encoderValueKL;

//Dunst
const int CLK_DU = 51;      
const int DT_DU = 53;
int SW_DU = A12;       
long oldPos_DU = -999;
bool enDU = false;
Bounce ENC_DU = Bounce(SW_DU, 10);
Encoder EncoderDU(DT_DU,CLK_DU);
int encoderValueDU;

//Dynamik
const int CLK_DY = 14;      
const int DT_DY = 15;
//int SW_DY = A8;       
long oldPos_DY = -999;
//bool enDY = false;
//Bounce ENC_DY = Bounce(SW_DY, 10);
Encoder EncoderDY(DT_DY,CLK_DY);
int encoderValueDY;

//Sättigung
const int CLK_SA = 35;      
const int DT_SA = 37;
//int SW_SA = A9;       
long oldPos_SA = -999;
//bool enSA = false;
//Bounce ENC_SA = Bounce(SW_SA, 10);
Encoder EncoderSA(DT_SA,CLK_SA);
int encoderValueSA;

//Verzerrung
const int CLK_VER = 27;      
const int DT_VER = 29;
int SW_VER = A6;       
long oldPos_VER = -999;
bool enVER = false;
Bounce ENC_VER = Bounce(SW_VER, 10);
Encoder EncoderVER(DT_VER,CLK_VER);
int encoderValueVER;

//System3
const int CLK_S3 = 7;      
const int DT_S3 = 8;
int SW_S3 = A11;       
long oldPos_S3 = -999;
bool enS3 = false;
Bounce ENC_S3 = Bounce(SW_S3, 10);
Encoder EncoderS3(DT_S3,CLK_S3);
int encoderValueS3;


//Non clickable Encoders

//J20
const int CLK_J20 = 40;      
const int DT_J20 = 38;
long oldPos_J20 = -999;
Encoder EncoderJ20(DT_J20,CLK_J20);
int encoderValueJ20;

//J21
const int CLK_J21 = 42;      
const int DT_J21 = 44;
long oldPos_J21 = -999;
Encoder EncoderJ21(DT_J21,CLK_J21);
int encoderValueJ21;

//J22
const int CLK_J22 = 24;      
const int DT_J22 = 22;
long oldPos_J22 = -999;
Encoder EncoderJ22(DT_J22,CLK_J22);
int encoderValueJ22;

//J23
const int CLK_J23 = 28;      
const int DT_J23 = 26;
long oldPos_J23 = -999;
Encoder EncoderJ23(DT_J23,CLK_J23);
int encoderValueJ23;

//J24
const int CLK_J24 = 32;      
const int DT_J24 = 30;
long oldPos_J24 = -999;
Encoder EncoderJ24(DT_J24,CLK_J24);
int encoderValueJ24;

//J25
const int CLK_J25 = 36;
const int DT_J25 = 34;
long oldPos_J25 = -999;
Encoder EncoderJ25(DT_J25,CLK_J25);
int encoderValueJ25;

//LED Config

#define PIN  13
#define NUMPIXELS 48

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//Some Colors

int red[3] = {0,255, 0};
int green[3] = {255, 0, 0};
int blue[3] = {0, 0, 255};
int orange[3] = {60, 255, 0};
int yellow[3] = {110, 140, 0};
int purple[3] = {0, 110, 200};
int white[3] = {255, 255, 255};
int aqua[3] = {30, 30, 200};
int magenta[3] = {0, 80, 180};
int colorSetLeft[][3] = { {230, 130, 0},{0, 0, 250}, {0, 0, 150}, {0, 0, 60}, {0, 0, 20}, {90, 90, 120}, {90, 90, 90}, {90, 90, 90}, {30, 17, 0}, {100, 50, 0}, {150, 80, 0}, {180, 110, 0}, };
int colorSetRight[][3] = { {0, 250, 0}, {0, 160, 0}, {0, 100, 0}, {0, 60, 0}, {90, 150, 90}, {90, 90, 90}, {90, 90, 90}, {120, 90, 130}, {10, 0, 18}, {30, 0, 56}, {120, 0, 200}, {100, 0, 200}};
//int colorEncoder[][3] = {{0,255, 0}, {60, 255, 0}, {110, 140, 0}, {255, 0, 0}, {120, 40, 120}, {0, 0, 255}, {0, 100, 180}, {0, 180, 90}};
int colorEncoder[][3] = { {0, 180, 90},{0, 100, 180},{0, 0, 255},{120, 40, 120}, {255, 0, 0}, {110, 140, 0}, {60, 255, 0},{0,255, 0}};


int modeEncoder = 0;
int modeColorEncoder = 0;
const int modeLimit = 2;
const int modeLimitColor = 3;

int modeValues[12][modeLimit] = {};
int modeValuesRingEncoder[5] = {};
int modeValuesColor[6][modeLimitColor] = {};



byte batteryState;

void testdrawline() {
  int16_t i;

  display.clearDisplay(); // Clear display buffer

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn line
    delay(1);
  }
  for(i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(50);

  display.clearDisplay();

  for(i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(50);

  display.clearDisplay();

  for(i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  delay(50);

  display.clearDisplay();

  for(i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, SSD1306_WHITE);
    display.display();
    delay(1);
  }
  for(i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, SSD1306_WHITE);
    display.display();
    delay(1);
  }

  delay(100); // Pause for 2 seconds
}

void testdrawrect(void) {
  display.clearDisplay();

  for(int16_t i=0; i<display.height()/2; i+=2) {
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, SSD1306_WHITE);
    display.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }

  delay(100);
}

void rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / pixels.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    }
    pixels.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

void printHomeScreen(String message) {
    display.clearDisplay();
    display.setTextSize(1); 
    display.setTextColor(WHITE);
    display.setCursor(1,56);
    display.println("General Admiral MIDI");
    display.setCursor(1,20);
    display.setTextSize(2); 
    display.println(message);
    display.display();
}


void setTwelveButtonsColor(int rgb[]){
  for(int i = 0; i < 12; i++){
    pixels.setPixelColor(i, pixels.Color(rgb[0], rgb[1], rgb[2]));
    pixels.show();
  }
}

void setColorEncoders(int colors[][3]){
  int count = 0;
  for(int i = 14; i < 22; i++){
    pixels.setPixelColor(i, pixels.Color(colors[count][0], colors[count][1], colors[count][2]));
    pixels.show();
    count++;
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

void sendMidiMsg(byte channel, byte mode, byte velocity){
  byte tmp[] = {0x0B, channel, mode, velocity};
  Serial1.write(tmp, 4);
}

void getMidiMsg(byte msg[]){
  Serial.println("Wir sind in getMidiMsg");
  if(msg[2] < 0x05){
    modeValuesRingEncoder[msg[2]] = msg[3];
  }
  else{
    if(msg[2] > 46){
      Serial2.write(msg, 4);   
    }
    else{
      modeValues[msg[2]][modeEncoder] = msg[3];
    }
  }
}

void readEncoderTEMP(){    
  long neuePosition; 
  encoderValueTEMP = modeValuesRingEncoder[0];
  neuePosition = EncoderTEMP.read();  
    if (neuePosition != oldPos_TEMP)
    {
      if (neuePosition > oldPos_TEMP + 3){
        if(encoderValueTEMP < 127){
          encoderValueTEMP++;
        }           
        sendMidiMsg(0xB0,0, encoderValueTEMP);            
        oldPos_TEMP = neuePosition;  
      }
      else if(neuePosition < oldPos_TEMP - 3){
        if(encoderValueTEMP > 0){              
          encoderValueTEMP--;
        }
        sendMidiMsg(0xB0, 0, encoderValueTEMP);            
        oldPos_TEMP = neuePosition;              
      }
      modeValuesRingEncoder[0] = encoderValueTEMP;   
      msgString = "Temperatur";
      displayCheck = true;  
    }
}

void readEncoderHUE(){    
  long neuePosition; 
  encoderValueHUE = modeValuesRingEncoder[1];
  neuePosition = EncoderHUE.read();  
    if (neuePosition != oldPos_HUE)
    {
      if (neuePosition > oldPos_HUE + 3){
        if(encoderValueHUE < 127){
          encoderValueHUE++;
        }           
        sendMidiMsg(0xB0, 0x01, encoderValueHUE);            
        oldPos_HUE = neuePosition;  
      }
      else if(neuePosition < oldPos_HUE - 3){
        if(encoderValueHUE > 0){              
          encoderValueHUE--;
        }
        sendMidiMsg(0xB0, 0x01, encoderValueHUE);            
        oldPos_HUE = neuePosition;              
      }
     modeValuesRingEncoder[1] = encoderValueHUE;
     msgString = "Toenung";
     displayCheck = true;  
    }
}

void readEncoderS1(){    
  long neuePosition; 
  encoderValueS1 = modeValuesRingEncoder[2];
  neuePosition = EncoderS1.read();  
    if (neuePosition != oldPos_S1)
    {
      if (neuePosition > oldPos_S1 + 3){
        if(encoderValueS1 < 127){
          encoderValueS1++;
        }           
        sendMidiMsg(0xB0, 0x02, 127);            
        oldPos_S1 = neuePosition;  
      }
      else if(neuePosition < oldPos_S1 - 3){
        if(encoderValueS1 > 0){              
          encoderValueS1--;
        }
        sendMidiMsg(0xB0, 0x70, 127);            
        oldPos_S1 = neuePosition;              
      }
     modeValuesRingEncoder[2] = encoderValueS1;  
    }
}

void readEncoderS2(){    
  long neuePosition; 
  encoderValueS2 = modeValuesRingEncoder[3];
  neuePosition = EncoderS2.read();  
    if (neuePosition != oldPos_S2)
    {
      if (neuePosition > oldPos_S2 + 3){
        if(encoderValueS2 < 127){
          encoderValueS2++;
        }           
        sendMidiMsg(0xB0, 0x03, 127);            
        oldPos_S2 = neuePosition;  
      }
      else if(neuePosition < oldPos_S2 - 3){
        if(encoderValueS2 > 0){              
          encoderValueS2--;
        }
        sendMidiMsg(0xB0, 0x69, 127);            
        oldPos_S2 = neuePosition;              
      }
     modeValuesRingEncoder[3] = encoderValueS2;  
    }
}

void readEncoderS3(){    
  long neuePosition; 
  encoderValueS3 = modeValuesRingEncoder[4];
  neuePosition = EncoderS3.read();  
    if (neuePosition != oldPos_S3)
    {
      if (neuePosition > oldPos_S3 + 3){
        if(encoderValueS3 < 127){
          encoderValueS3++;
        }           
        sendMidiMsg(0xB0, 0x04, encoderValueS3);            
        oldPos_S3 = neuePosition;  
      }
      else if(neuePosition < oldPos_S3 - 3){
        if(encoderValueS3 > 0){              
          encoderValueS3--;
        }
        sendMidiMsg(0xB0, 0x04, encoderValueS3);            
        oldPos_S3 = neuePosition;              
      }
     modeValuesRingEncoder[4] = encoderValueS3;  
    }
}

void readEncoderBEL(){    
  long neuePosition; 
  encoderValueBEL = modeValues[0][modeEncoder];
  neuePosition = EncoderBEL.read();  
    if (neuePosition != oldPos_BEL)
    {
      if (neuePosition > oldPos_BEL + 3){
        if(encoderValueBEL < 127){
          encoderValueBEL++;
        }           
        sendMidiMsg(0xB0, 0x05 + modeEncoder, encoderValueBEL);            
        oldPos_BEL = neuePosition;  
      }
      else if(neuePosition < oldPos_BEL - 3){
        if(encoderValueBEL > 0){              
          encoderValueBEL--;
        }
        sendMidiMsg(0xB0, 0x05 + modeEncoder, encoderValueBEL);            
        oldPos_BEL = neuePosition;              
      }
      modeValues[0][modeEncoder] = encoderValueBEL;  
    }
}

void readEncoderKON(){    
  long neuePosition; 
  encoderValueKON = modeValues[1][modeEncoder];
  neuePosition = EncoderKON.read();  
    if (neuePosition != oldPos_KON)
    {
      if (neuePosition > oldPos_KON + 3){
        if(encoderValueKON < 127){
          encoderValueKON++;
        }           
        sendMidiMsg(0xB0, 0x07 +modeEncoder, encoderValueKON);            
        oldPos_KON = neuePosition;  
      }
      else if(neuePosition < oldPos_KON - 3){
        if(encoderValueKON > 0){              
          encoderValueKON--;
        }
        sendMidiMsg(0xB0, 0x07 + modeEncoder, encoderValueKON);            
        oldPos_KON = neuePosition;              
      }
      modeValues[1][modeEncoder] = encoderValueKON;  
    }
}

void readEncoderLI(){    
  long neuePosition; 
  encoderValueLI = modeValues[2][modeEncoder];
  neuePosition = EncoderLI.read();  
    if (neuePosition != oldPos_LI)
    {
      if (neuePosition > oldPos_LI + 3){
        if(encoderValueLI < 127){
          encoderValueLI++;
        }           
        sendMidiMsg(0xB0, 0x09 +modeEncoder, encoderValueLI);            
        oldPos_LI = neuePosition;  
      }
      else if(neuePosition < oldPos_LI - 3){
        if(encoderValueLI > 0){              
          encoderValueLI--;
        }
        sendMidiMsg(0xB0, 0x09 + modeEncoder, encoderValueLI);            
        oldPos_LI = neuePosition;              
      }
      modeValues[2][modeEncoder] = encoderValueLI;  
    }
}

void readEncoderTI(){    
  long neuePosition; 
  encoderValueTI = modeValues[3][modeEncoder];
  neuePosition = EncoderTI.read();  
    if (neuePosition != oldPos_TI)
    {
      if (neuePosition > oldPos_TI + 3){
        if(encoderValueTI < 127){
          encoderValueTI++;
        }           
        sendMidiMsg(0xB0, 11 +modeEncoder, encoderValueTI);            
        oldPos_TI = neuePosition;  
      }
      else if(neuePosition < oldPos_TI - 3){
        if(encoderValueTI > 0){              
          encoderValueTI--;
        }
        sendMidiMsg(0xB0, 11 + modeEncoder, encoderValueTI);            
        oldPos_TI = neuePosition;              
      }
      modeValues[3][modeEncoder] = encoderValueTI;  
    }
}

void readEncoderWE(){    
  long neuePosition; 
  encoderValueWE = modeValues[4][modeEncoder];
  neuePosition = EncoderWE.read();  
    if (neuePosition != oldPos_WE)
    {
      if (neuePosition > oldPos_WE + 3){
        if(encoderValueWE < 127){
          encoderValueWE++;
        }           
        sendMidiMsg(0xB0, 13 +modeEncoder, encoderValueWE);            
        oldPos_WE = neuePosition;  
      }
      else if(neuePosition < oldPos_WE - 3){
        if(encoderValueWE > 0){              
          encoderValueWE--;
        }
        sendMidiMsg(0xB0, 13 + modeEncoder, encoderValueWE);            
        oldPos_WE = neuePosition;              
      }
      modeValues[4][modeEncoder] = encoderValueWE;  
    }
}

void readEncoderSW(){    
  long neuePosition; 
  encoderValueSW = modeValues[5][modeEncoder];
  neuePosition = EncoderSW.read();  
    if (neuePosition != oldPos_SW)
    {
      if (neuePosition > oldPos_SW + 3){
        if(encoderValueSW < 127){
          encoderValueSW++;
        }           
        sendMidiMsg(0xB0, 15 +modeEncoder, encoderValueSW);            
        oldPos_SW = neuePosition;  
      }
      else if(neuePosition < oldPos_SW - 3){
        if(encoderValueSW > 0){              
          encoderValueSW--;
        }
        sendMidiMsg(0xB0, 15 + modeEncoder, encoderValueSW);            
        oldPos_SW = neuePosition;              
      }
      modeValues[5][modeEncoder] = encoderValueSW;  
    }
}

void readEncoderST(){    
  long neuePosition; 
  encoderValueST = modeValues[6][modeEncoder];
  neuePosition = EncoderST.read();  
    if (neuePosition != oldPos_ST)
    {
      if (neuePosition > oldPos_ST + 3){
        if(encoderValueST < 127){
          encoderValueST++;
        }           
        sendMidiMsg(0xB0, 17 +modeEncoder, encoderValueST);            
        oldPos_ST = neuePosition;  
      }
      else if(neuePosition < oldPos_ST - 3){
        if(encoderValueST > 0){              
          encoderValueST--;
        }
        sendMidiMsg(0xB0, 17 + modeEncoder, encoderValueST);            
        oldPos_ST = neuePosition;              
      }
      modeValues[6][modeEncoder] = encoderValueST;  
    }
}

void readEncoderKL(){    
  long neuePosition; 
  encoderValueKL = modeValues[7][modeEncoder];
  neuePosition = EncoderKL.read();  
    if (neuePosition != oldPos_KL)
    {
      if (neuePosition > oldPos_KL + 3){
        if(encoderValueKL < 127){
          encoderValueKL++;
        }           
        sendMidiMsg(0xB0, 19 +modeEncoder, encoderValueKL);            
        oldPos_KL = neuePosition;  
      }
      else if(neuePosition < oldPos_KL - 3){
        if(encoderValueKL > 0){              
          encoderValueKL--;
        }
        sendMidiMsg(0xB0, 19 + modeEncoder, encoderValueKL);            
        oldPos_KL = neuePosition;              
      }
      modeValues[7][modeEncoder] = encoderValueKL;  
    }
}

void readEncoderDU(){    
  long neuePosition; 
  encoderValueDU = modeValues[8][modeEncoder];
  neuePosition = EncoderDU.read();  
    if (neuePosition != oldPos_DU)
    {
      if (neuePosition > oldPos_DU + 3){
        if(encoderValueDU < 127){
          encoderValueDU++;
        }           
        sendMidiMsg(0xB0, 21 +modeEncoder, encoderValueDU);            
        oldPos_DU = neuePosition;  
      }
      else if(neuePosition < oldPos_DU - 3){
        if(encoderValueDU > 0){              
          encoderValueDU--;
        }
        sendMidiMsg(0xB0, 21 + modeEncoder, encoderValueDU);            
        oldPos_DU = neuePosition;              
      }
      modeValues[8][modeEncoder] = encoderValueDU;  
    }
}

void readEncoderDY(){    
  long neuePosition; 
  encoderValueDY = modeValues[9][modeEncoder];
  neuePosition = EncoderDY.read();  
    if (neuePosition != oldPos_DY)
    {
      if (neuePosition > oldPos_DY + 3){
        if(encoderValueDY < 127){
          encoderValueDY++;
        }           
        sendMidiMsg(0xB0, 23 +modeEncoder, encoderValueDY);            
        oldPos_DY = neuePosition;  
      }
      else if(neuePosition < oldPos_DY - 3){
        if(encoderValueDY > 0){              
          encoderValueDY--;
        }
        sendMidiMsg(0xB0, 23 + modeEncoder, encoderValueDY);            
        oldPos_DY = neuePosition;              
      }
      modeValues[9][modeEncoder] = encoderValueDY;  
    }
}

void readEncoderSA(){    
  long neuePosition; 
  encoderValueSA = modeValues[10][modeEncoder];
  neuePosition = EncoderSA.read();  
    if (neuePosition != oldPos_SA)
    {
      if (neuePosition > oldPos_SA + 3){
        if(encoderValueSA < 127){
          encoderValueSA++;
        }           
        sendMidiMsg(0xB0, 25 +modeEncoder, encoderValueSA);            
        oldPos_SA = neuePosition;  
      }
      else if(neuePosition < oldPos_SA - 3){
        if(encoderValueSA > 0){              
          encoderValueSA--;
        }
        sendMidiMsg(0xB0, 25 + modeEncoder, encoderValueSA);            
        oldPos_SA = neuePosition;              
      }
      modeValues[10][modeEncoder] = encoderValueSA;  
    }
}

void readEncoderVER(){    
  long neuePosition; 
  encoderValueVER = modeValues[11][modeEncoder];
  neuePosition = EncoderVER.read();  
    if (neuePosition != oldPos_VER)
    {
      if (neuePosition > oldPos_VER + 3){
        if(encoderValueVER < 127){
          encoderValueVER++;
        }           
        sendMidiMsg(0xB0, 27 +modeEncoder, encoderValueVER);            
        oldPos_VER = neuePosition;  
      }
      else if(neuePosition < oldPos_VER - 3){
        if(encoderValueVER > 0){              
          encoderValueVER--;
        }
        sendMidiMsg(0xB0, 27 + modeEncoder, encoderValueVER);            
        oldPos_VER = neuePosition;              
      }
      modeValues[11][modeEncoder] = encoderValueVER;  
    }
}

void readEncoderJ20(){    
  long neuePosition; 
  encoderValueJ20 = modeValuesColor[0][modeColorEncoder];
  neuePosition = EncoderJ20.read();  
    if (neuePosition != oldPos_J20)
    {
      if (neuePosition > oldPos_J20 + 3){
        if(encoderValueJ20 < 127){
          encoderValueJ20++;
        }           
        sendMidiMsg(0xB0, 29 +modeColorEncoder, encoderValueJ20);            
        oldPos_J20 = neuePosition;  
      }
      else if(neuePosition < oldPos_J20 - 3){
        if(encoderValueJ20 > 0){              
          encoderValueJ20--;
        }
        sendMidiMsg(0xB0, 29 + modeColorEncoder, encoderValueJ20);            
        oldPos_J20 = neuePosition;              
      }
      modeValuesColor[0][modeColorEncoder] = encoderValueJ20;  
    }
}

void readEncoderJ21(){    
  long neuePosition; 
  encoderValueJ21 = modeValuesColor[1][modeColorEncoder];
  neuePosition = EncoderJ21.read();  
    if (neuePosition != oldPos_J21)
    {
      if (neuePosition > oldPos_J21 + 3){
        if(encoderValueJ21 < 127){
          encoderValueJ21++;
        }           
        sendMidiMsg(0xB0, 32 +modeColorEncoder, encoderValueJ21);            
        oldPos_J21 = neuePosition;  
      }
      else if(neuePosition < oldPos_J21 - 3){
        if(encoderValueJ21 > 0){              
          encoderValueJ21--;
        }
        sendMidiMsg(0xB0, 32 + modeColorEncoder, encoderValueJ21);            
        oldPos_J21 = neuePosition;              
      }
      modeValuesColor[1][modeColorEncoder] = encoderValueJ21;  
    }
}

void readEncoderJ22(){    
  long neuePosition; 
  encoderValueJ22 = modeValuesColor[2][modeColorEncoder];
  neuePosition = EncoderJ22.read();  
    if (neuePosition != oldPos_J22)
    {
      if (neuePosition > oldPos_J22 + 3){
        if(encoderValueJ22 < 127){
          encoderValueJ22++;
        }           
        sendMidiMsg(0xB0, 35 +modeColorEncoder, encoderValueJ22);            
        oldPos_J22 = neuePosition;  
      }
      else if(neuePosition < oldPos_J22 - 3){
        if(encoderValueJ22 > 0){              
          encoderValueJ22--;
        }
        sendMidiMsg(0xB0, 35 + modeColorEncoder, encoderValueJ22);            
        oldPos_J22 = neuePosition;              
      }
      modeValuesColor[2][modeColorEncoder] = encoderValueJ22;  
    }
}

void readEncoderJ23(){    
  long neuePosition; 
  encoderValueJ23 = modeValuesColor[3][modeColorEncoder];
  neuePosition = EncoderJ23.read();  
    if (neuePosition != oldPos_J23)
    {
      if (neuePosition > oldPos_J23 + 3){
        if(encoderValueJ23 < 127){
          encoderValueJ23++;
        }           
        sendMidiMsg(0xB0, 38 +modeColorEncoder, encoderValueJ23);            
        oldPos_J23 = neuePosition;  
      }
      else if(neuePosition < oldPos_J23 - 3){
        if(encoderValueJ23 > 0){              
          encoderValueJ23--;
        }
        sendMidiMsg(0xB0, 38 + modeColorEncoder, encoderValueJ23);            
        oldPos_J23 = neuePosition;              
      }
      modeValuesColor[3][modeColorEncoder] = encoderValueJ23;  
    }
}

void readEncoderJ24(){    
  long neuePosition; 
  encoderValueJ24 = modeValuesColor[4][modeColorEncoder];
  neuePosition = EncoderJ24.read();  
    if (neuePosition != oldPos_J24)
    {
      if (neuePosition > oldPos_J24 + 3){
        if(encoderValueJ24 < 127){
          encoderValueJ24++;
        }           
        sendMidiMsg(0xB0, 41 +modeColorEncoder, encoderValueJ24);            
        oldPos_J24 = neuePosition;  
      }
      else if(neuePosition < oldPos_J24 - 3){
        if(encoderValueJ24 > 0){              
          encoderValueJ24--;
        }
        sendMidiMsg(0xB0, 41 + modeColorEncoder, encoderValueJ24);            
        oldPos_J24 = neuePosition;              
      }
      modeValuesColor[4][modeColorEncoder] = encoderValueJ24;  
    }
}

void readEncoderJ25(){    
  long neuePosition; 
  encoderValueJ25 = modeValuesColor[5][modeColorEncoder];
  neuePosition = EncoderJ25.read();  
    if (neuePosition != oldPos_J25)
    {
      if (neuePosition > oldPos_J25 + 3){
        if(encoderValueJ25 < 127){
          encoderValueJ25++;
        }           
        sendMidiMsg(0xB0, 44 +modeColorEncoder, encoderValueJ25);            
        oldPos_J25 = neuePosition;  
      }
      else if(neuePosition < oldPos_J25 - 3){
        if(encoderValueJ25 > 0){              
          encoderValueJ25--;
        }
        sendMidiMsg(0xB0, 44 + modeColorEncoder, encoderValueJ25);            
        oldPos_J25 = neuePosition;              
      }
      modeValuesColor[5][modeColorEncoder] = encoderValueJ25;  
    }
}


void readEncoder() {
  readEncoderKON();
  readEncoderBEL();
  readEncoderHUE();
  readEncoderTEMP();
  readEncoderS1();
  readEncoderS2();
  readEncoderS3();
  readEncoderLI();
  readEncoderTI();
  readEncoderWE();
  readEncoderSW();
  readEncoderST();
  readEncoderKL();
  readEncoderDU();
  readEncoderDY();
  readEncoderSA();
  readEncoderVER();
  readEncoderJ20();
  readEncoderJ21();
  readEncoderJ22();
  readEncoderJ23();
  readEncoderJ24();
  readEncoderJ25();
}


void noteOn(byte channel, byte pitch, byte velocity) {
  byte tmp[] = {0x09, 0x90 | pitch, channel, velocity};
  Serial1.write(tmp, 4);
}
void noteOff(byte channel, byte pitch, byte velocity) {
  byte tmp[] = {0x08, 0x80 | pitch, channel, velocity};
  Serial1.write(tmp, 4);
}

void EncoderClicks(){
  if(ENC_TEMP.update()){
    if(!enTEMP){
      noteOn(1, 1, 127);
      enTEMP = true;
    }
    else{
      noteOff(1, 1, 0);
      enTEMP = false;
    }
  }
   if(ENC_HUE.update()){
    if(!enHUE){
      noteOn(2, 1, 127);
      enHUE = true;
    }
    else{
      noteOff(2, 1, 0);
      enHUE = false;
    }
  }
  if(ENC_KON.update()){
    if(!enKON){
      noteOn(3, modeEncoder, 127);
      enKON = true;
    }
    else{
      noteOff(3, modeEncoder, 0);
      enKON = false;
    }
  }
  if(ENC_BEL.update()){
    if(!enBEL){
      noteOn(4, modeEncoder, 127);
      enBEL = true;
    }
    else{
      noteOff(4, modeEncoder, 0);
      enBEL = false;
    }
  }
  if(ENC_S1.update()){
    if(!enS1){
      noteOn(5, 1, 127);
      enS1 = true;
    }
    else{
      noteOff(5, 1, 0);
      enS1 = false;
    }
  }
  if(ENC_S2.update()){
    if(!enS2){
      noteOn(6, 1, 127);
      enS2 = true;
    }
    else{
      noteOff(6, 1, 0);
      enS2 = false;
    }
  }
  if(ENC_S3.update()){
    if(!enS3){
      noteOn(7, 1, 127);
      enS3 = true;
    }
    else{
      noteOff(7, 1, 0);
      enS3 = false;
    }
  }
  if(ENC_LI.update()){
    if(!enLI){
      noteOn(8, modeEncoder, 127);
      enLI = true;
    }
    else{
      noteOff(8, modeEncoder, 0);
      enLI = false;
    }
  }
  if(ENC_TI.update()){
    if(!enTI){
      noteOn(9, modeEncoder, 127);
      enTI = true;
    }
    else{
      noteOff(9, modeEncoder, 0);
      enTI = false;
    }
  }
  if(ENC_WE.update()){
    if(!enWE){
      noteOn(10, modeEncoder, 127);
      enWE = true;
    }
    else{
      noteOff(10, modeEncoder, 0);
      enWE = false;
    }
  }
  if(ENC_SW.update()){
    if(!enSW){
      noteOn(11, modeEncoder, 127);
      enSW = true;
    }
    else{
      noteOff(11, modeEncoder, 0);
      enSW = false;
    }
  }
  if(ENC_ST.update()){
    if(!enST){
      noteOn(12, modeEncoder, 127);
      enST = true;
    }
    else{
      noteOff(12, modeEncoder, 0);
      enST = false;
    }
  }
  if(ENC_KL.update()){
    if(!enKL){
      noteOn(13, modeEncoder, 127);
      enKL = true;
    }
    else{
      noteOff(13, modeEncoder, 0);
      enKL = false;
    }
  }
  if(ENC_DU.update()){
    if(!enDU){
      noteOn(14, modeEncoder, 127);
      enDU = true;
    }
    else{
      noteOff(14, modeEncoder, 0);
      enDU = false;
    }
  }
 
  if(ENC_VER.update()){
    if(!enVER){
      noteOn(17, modeEncoder, 127);
      enVER = true;
    }
    else{
      noteOff(17, modeEncoder, 0);
      enVER = false;
    }
  }
}

void buttonClick(byte button){
  switch (button){
    case 1:
      noteOn(18, 1, 127);
      noteOff(18, 1, 0);
      pixels.setPixelColor(0, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("1");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 2:
      noteOn(19, 1, 127);
      noteOff(19, 1, 0);
      pixels.setPixelColor(3, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      delay(200);
      Serial.println("2");
      setTwelveButtonsColor(white);
      break;
    case 3:
      noteOn(20, 1, 127);
      noteOff(20, 1, 0);
      pixels.setPixelColor(1, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("3");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 4:
      noteOn(21, 1, 127);
      noteOff(21, 1, 0);
      pixels.setPixelColor(4, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("4");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 5:
      noteOn(22, 1, 127);
      noteOff(22, 1, 0);
      pixels.setPixelColor(2, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("5");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 6:
      noteOn(23, 1, 127);
      noteOff(23, 1, 0);
      pixels.setPixelColor(5, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("6");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 7:
      noteOn(24, 1, 127);
      noteOff(24, 1, 0);
      pixels.setPixelColor(9, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("7");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 8:
      noteOn(25, 1, 127);
      noteOff(25, 1, 0);
      pixels.setPixelColor(8, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("8");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 9:
      noteOn(26, 1, 127);
      noteOff(26, 1, 0);
      pixels.setPixelColor(10, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("9");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 10:
      noteOn(27, 1, 127);
      noteOff(27, 1, 0);
      pixels.setPixelColor(7, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("10");
      delay(200);
      setTwelveButtonsColor(white);
      break;
   case 11:
      noteOn(29, 1, 127);
      noteOff(29, 1, 0);
      pixels.setPixelColor(11, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("11");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 12:
      noteOn(28, 1, 127);
      noteOff(28, 1, 0);
      pixels.setPixelColor(6, pixels.Color(0, 250, 0));
      pixels.show();
      //timer = millis();
      Serial.println("12");
      delay(200);
      setTwelveButtonsColor(white);
      break;
    case 14:
      if (modeEncoder == 1){
        modeEncoder = 0; 
      }
      else{
        modeEncoder++;
      }
      break;
    case 13:
      if(modeColorEncoder == 2){
        modeColorEncoder = 0;
      }
      else{ 
        modeColorEncoder++;
      }
      byte msg[4] = {1, 1, 1, modeColorEncoder};
      Serial2.write(msg, 4);
      break;
  }
}

void setEncLed(){
  int red1 = 0;
  int blue1 = 0;
  int green1 = 0;
  if(modeValuesRingEncoder[0] < 30){
    red1=0;
    blue1=0;
    green1=250;
  }
  else if(modeValuesRingEncoder[0] > 92){
    red1=224;
    blue1=180;
    green1=20;
  }
  else{
    if(modeValuesRingEncoder[0] > 64){
      red1=modeValuesRingEncoder[0]*2.4;
      blue1=modeValuesRingEncoder[0]*2;
      green1= 256-(2.5*modeValuesRingEncoder[0]-1);
    }
    else{
      red1=modeValuesRingEncoder[0]*1.8;
      blue1=modeValuesRingEncoder[0]*1.4;
      green1=256-(1.4*modeValuesRingEncoder[0]-1);
    }
  }
  int red2 = 0;
  int blue2 = 0;
  int green2 = 0;
  if(modeValuesRingEncoder[1] < 30){
    red2=0;
    blue2=230;
    green2=0;
  }
  else if(modeValuesRingEncoder[1] > 92){
    red2=234;
    blue2=0;
    green2=110;
  }
  else{
    if(modeValuesRingEncoder[1] > 64){
      red2=modeValuesRingEncoder[1]*2.7;
      blue2=256-(2.5*modeValuesRingEncoder[1]-1);
      green2= modeValuesRingEncoder[1]*1.3 ;
    }
    else{
      red2=modeValuesRingEncoder[1]+5;
      blue2=256 - modeValuesRingEncoder[1]*0.7;
      green2=modeValuesRingEncoder[1]+5;
    }
  }
  pixels.setPixelColor(46, pixels.Color(green1, red1, blue1));
  pixels.show();
  pixels.setPixelColor(47, pixels.Color(green2, red2, blue2));
  pixels.show();
}
void readNano(){
  byte msgFromNano[4] = {0,0,0,0};
  if(Serial2.available() >= 4){
    for(int i=0; i<4; i++){
      msgFromNano[i] = Serial2.read();
    }
    //button press
    if(msgFromNano[0] == 5){
      buttonClick(msgFromNano[1]);
      
      Serial.println("Got a 0!");
    }
    //encoder move
    else if(msgFromNano[0] == 1){
      sendMidiMsg(msgFromNano[1], msgFromNano[2], msgFromNano[3]); 
      //Serial.println("Got a 1!");
      //Serial.println("1.BYTE:  "); 
      //Serial.println(msgFromNano[0]);
      //Serial.println("2.BYTE:  ");
      //Serial.println(msgFromNano[1]);
      //Serial.println("3.BYTE:  ");
      //Serial.println(msgFromNano[2]);
      //Serial.println("4.BYTE:  ");
      //Serial.println(msgFromNano[3]);
      //Serial.println("END");
    }
    //status msg
    else if(msgFromNano[0] == 2){
      batteryState = msgFromNano[1];
    }
    else if(msgFromNano[0] == 3){
      //Serial.println("Got a 3!");
      noteOn(16, modeEncoder, 127);
      noteOff(16, modeEncoder, 1);
    }
    else if(msgFromNano[0] == 4){
      //Serial.println("Got a 4!");
      noteOn(15, modeEncoder, 127);
      noteOff(15, modeEncoder, 1);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial2.begin(9600);
  pinMode(SW_TEMP, INPUT); 
  pinMode(SW_HUE, INPUT);
  pinMode(SW_BEL, INPUT);
  pinMode(SW_KON, INPUT);
  pinMode(SW_LI, INPUT);
  pinMode(SW_TI, INPUT);
  pinMode(SW_WE, INPUT);
  pinMode(SW_SW, INPUT);
  pinMode(SW_S1, INPUT);
  pinMode(SW_S2, INPUT);
  pinMode(SW_S3, INPUT);
  pinMode(SW_ST, INPUT);
  pinMode(SW_KL, INPUT);
  pinMode(SW_DU, INPUT);
  //pinMode(SW_DY, INPUT);
  //pinMode(SW_SA, INPUT);
  pinMode(SW_VER, INPUT);
  pixels.begin();
  rainbow(0);
  setTwelveButtonsColor(white);
  setLeftColorWheel(colorSetLeft);
  setRightColorWheel(colorSetRight);
  setColorEncoders(colorEncoder);
  for(int i=0; i<12; i++){
    for(int j=0; j<2; j++){
      modeValues[i][j] = 64;
    }
  }
  for(int i=0; i<5; i++){
    modeValuesRingEncoder[i] = 64;
  }
  for(int i=0; i<6; i++){
    for(int j=0; j<3; j++){
      modeValuesColor[i][j] = 64;
    }
  }
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    //Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(100);
  display.clearDisplay();
  //testdrawline();     
  testdrawrect();
  delay(200);
  display.clearDisplay();
  display.display(); 
  timer = millis();
  printHomeScreen("");
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() >= 4){
    byte bytes[4] = {0,0,0,0};
    for(int i=0; i<4; i++){
      bytes[i] = Serial1.read();
    }
    getMidiMsg(bytes);
  }
  
  readNano();
  readEncoder();
  EncoderClicks();
  
  if(modeEncoder == 0){
    pixels.setPixelColor(12, pixels.Color(60, 255, 0));
    pixels.show();
      }
  else if(modeEncoder == 1){
    pixels.setPixelColor(12, pixels.Color(120, 40, 120));
    pixels.show();
      }
  if(modeColorEncoder == 0){
    pixels.setPixelColor(13, pixels.Color(60, 255, 0));
    pixels.show();
      }
  else if(modeColorEncoder == 1){
    pixels.setPixelColor(13, pixels.Color(120, 40, 120));
    pixels.show();
      }
  else if(modeColorEncoder == 2){
    pixels.setPixelColor(13, pixels.Color(0, 180, 90));
    pixels.show();
  }
  setEncLed();
  //if(timer + 300 < millis()){
    //setTwelveButtonsColor(white);
  //}
 // if(timer + 3000 < millis()){
  //  printHomeScreen("LOOOOOOOOL");
  //  timer = millis();
 // } 
 // if(displayCheck){
//    printHomeScreen(msgString);
 //   displayCheck = false;
 //   timer = millis();
 // } 
}
