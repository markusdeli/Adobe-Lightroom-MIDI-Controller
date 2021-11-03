#include <Bounce2.h>
#include <Encoder.h>

int modeColorEncoder = 0;

int modeValuesColor[2][3] = { 64 };

byte msgFromMega[4];


//int button1 = A6;
int button2 = 10;
int button3 = A5;
int button4 = A4;
int button5 = A3;
int button6 = A2;
int button7 = 2;
int button8 = 3;
int button9 = 4;
int button10 = 5;
int button11 = 6;
int button12 = 7;
int button13 = 8;
int button14 = 9;

//bool bb1 = false;
bool bb2 = false;
bool bb3 = false;
bool bb4 = false;
bool bb5 = false;
bool bb6 = false;
bool bb7 = false;
bool bb8 = false;
bool bb9 = false;
bool bb10 = false;
bool bb11 = false;
bool bb12 = false;
bool bb13 = false;
bool bb14 = false;

//Bounce b1 = Bounce(button1, 10);
Bounce b2 = Bounce(button2, 10);
Bounce b3 = Bounce(button3, 10);
Bounce b4 = Bounce(button4, 10);
Bounce b5 = Bounce(button5, 10);
Bounce b6 = Bounce(button6, 10);
Bounce b7 = Bounce(button7, 10);
Bounce b8 = Bounce(button8, 10);
Bounce b9 = Bounce(button9, 10);
Bounce b10 = Bounce(button10, 10);
Bounce b11 = Bounce(button11, 10);
Bounce b12 = Bounce(button12, 10);
Bounce b13 = Bounce(button13, 10);
Bounce b14 = Bounce(button14, 10);

//J26
const int CLK_J26 = 12;      
const int DT_J26 = 13;// auf pin 13 ändern
long oldPos_J26 = -999;
Encoder EncoderJ26(DT_J26,CLK_J26);
int encoderValueJ26;

//J27
const int CLK_J27 = 11;      
const int DT_J27 = A1;
long oldPos_J27 = -999;
Encoder EncoderJ27(DT_J27,CLK_J27);
int encoderValueJ27;

void readEncoderJ26(){    
  long neuePosition; 
  encoderValueJ26 = modeValuesColor[0][modeColorEncoder];
  neuePosition = EncoderJ26.read();  
    if (neuePosition != oldPos_J26)
    {
      if (neuePosition > oldPos_J26 + 3){
        if(encoderValueJ26 < 127){
          encoderValueJ26++;
        }           
        sendMidiMsg(1, 0xB0, 47 +modeColorEncoder, encoderValueJ26);            
        oldPos_J26 = neuePosition;  
      }
      else if(neuePosition < oldPos_J26 - 3){
        if(encoderValueJ26 > 0){              
          encoderValueJ26--;
        }
        sendMidiMsg(1, 0xB0, 47 + modeColorEncoder, encoderValueJ26);            
        oldPos_J26 = neuePosition;              
      }
      modeValuesColor[0][modeColorEncoder] = encoderValueJ26;  
    }
}

void readEncoderJ27(){    
  long neuePosition; 
  encoderValueJ27 = modeValuesColor[1][modeColorEncoder];
  neuePosition = EncoderJ27.read();  
    if (neuePosition != oldPos_J27)
    {
      if (neuePosition > oldPos_J27 + 3){
        if(encoderValueJ27 < 127){
          encoderValueJ27++;
        }           
        sendMidiMsg(1 ,0xB0, 50 +modeColorEncoder, encoderValueJ27);            
        oldPos_J27 = neuePosition;  
      }
      else if(neuePosition < oldPos_J27 - 3){
        if(encoderValueJ27 > 0){              
          encoderValueJ27--;
        }
        sendMidiMsg(1,0xB0, 50 + modeColorEncoder, encoderValueJ27);            
        oldPos_J27 = neuePosition;              
      }
      modeValuesColor[1][modeColorEncoder] = encoderValueJ27;  
    }
}

void getEncoderValues(){
  if(Serial.available() >= 4){
    for(int i=0; i<4; i++){
      msgFromMega[i] = Serial.read();
    }
    if(msgFromMega[0] == 1 && msgFromMega[1] == 1 && msgFromMega[2] == 1){
      modeColorEncoder = msgFromMega[3];
    }
    else if(msgFromMega[2] < 50){
      modeValuesColor[0][modeColorEncoder] = msgFromMega[3];
    }
    else{
      modeValuesColor[1][modeColorEncoder] = msgFromMega[3];
    }
  }
}

void sendMidiMsg(byte state, byte channel, byte mode, byte velocity){
  byte tmp[] = {state, channel, mode, velocity};
  Serial.write(tmp, 4);
}

void setup() {
  // put your setup code here, to run once:
  
 // pinMode(button1, INPUT);  
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);
  pinMode(button10, INPUT);
  pinMode(button11, INPUT);
  pinMode(button12, INPUT);
  pinMode(button13, INPUT);
  pinMode(button14, INPUT);
  Serial.begin(9600);
}

void loop() {
  //if(b1.update()){
    //if(!bb1){
     // byte msg[4] = {5, 1, 10, 10};
     // Serial.write(msg, 4);
     // bb1 = true; 
    //}
   // else{
   //   bb1 = false;
   // }
 // }
  if(b2.update()){
    if(!bb2){
      byte msg[4] = {5, 2, 10, 10};
      Serial.write(msg, 4);
      bb2 = true; 
    }
    else{
      bb2 = false;
    }
  }
  if(b3.update()){
    if(!bb3){
      byte msg[4] = {5, 3, 10, 10};
      Serial.write(msg, 4);
      bb3 = true; 
    }
    else{
      bb3 = false;
    }
  }
  if(b4.update()){
    if(!bb4){
      byte msg[4] = {5, 4, 10, 10};
      Serial.write(msg, 4);
      bb4 = true; 
    }
    else{
      bb4 = false;
    }
  }
  if(b5.update()){
    if(!bb5){
      byte msg[4] = {5, 5, 10, 10};
      Serial.write(msg, 4);
      bb5 = true; 
    }
    else{
      bb5 = false;
    }
  }
  if(b6.update()){
    if(!bb6){
      byte msg[4] = {5, 6, 10, 10};
      Serial.write(msg, 4);
      bb6 = true; 
    }
    else{
      bb6 = false;
    }
  }
  if(b7.update()){
    if(!bb7){
      byte msg[4] = {5, 7, 10, 10};
      Serial.write(msg, 4);
      bb7 = true; 
    }
    else{
      bb7 = false;
    }
  }
  if(b8.update()){
    if(!bb8){
      byte msg[4] = {5, 8, 10, 10};
      Serial.write(msg, 4);
      bb8 = true; 
    }
    else{
      bb8 = false;
    }
  }
  if(b9.update()){
    if(!bb9){
      byte msg[4] = {5, 9, 10, 10};
      Serial.write(msg, 4);
      bb9 = true; 
    }
    else{
      bb9 = false;
    }
  }
  if(b10.update()){
    if(!bb10){
      byte msg[4] = {5, 10, 10, 10};
      Serial.write(msg, 4);
      bb10 = true; 
    }
    else{
      bb10 = false;
    }
  }
  if(b11.update()){
    if(!bb11){
      byte msg[4] = {5, 11, 10, 10};
      Serial.write(msg, 4);
      bb11 = true; 
    }
    else{
      bb11 = false;
    }
  }
  if(b12.update()){
    if(!bb12){
      byte msg[4] = {5, 12, 10, 10};
      Serial.write(msg, 4);
      bb12 = true; 
    }
    else{
      bb12 = false;
    }
  }
  if(b13.update()){
    if(!bb13){
      byte msg[4] = {5, 13, 10, 10};
      Serial.write(msg, 4);
      bb13 = true; 
    }
    else{
      bb13 = false;
    }
  }
  if(b14.update()){
    if(!bb14){
      byte msg[4] = {5, 14, 10, 10};
      Serial.write(msg, 4);
      bb14 = true; 
    }
    else{
      bb14 = false;
    }
  }
  readEncoderJ26();
  readEncoderJ27();
  getEncoderValues();
}
