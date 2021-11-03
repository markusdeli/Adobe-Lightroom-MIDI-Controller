#include <Encoder.h>

const int CLK = 9;     
const int DT = 8;

long position1 = -999;
int encoderValue; 
Encoder myEnc(DT,CLK);

int mode = 0;
const int modeLimit = 48;
int modeValues[modeLimit] = { 64 };

void setup() {
  Serial3.begin(9600);
  Serial.begin(9600);

}

void loop() {
  readEncoder();
  if(Serial3.available() >= 4){
    byte bytes[4];
    for(int i=0; i<4; i++){
      bytes[i] = Serial3.read();
    }
    getMidiMsg(bytes);
  }
}

void readEncoder(){    
  long neuePosition; 
  encoderValue = modeValues[mode];
  neuePosition = myEnc.read();  
    if (neuePosition != position1)
    {
      if (neuePosition > position1 + 3){
        if(encoderValue < 127){
          encoderValue++;
        }           
        sendMidiMsg(0xB0, mode, encoderValue);            
        position1 = neuePosition;  
      }
      else if(neuePosition < position1 - 3){
        if(encoderValue > 0){              
          encoderValue--;
        }
        sendMidiMsg(0xB0, mode, encoderValue);            
        position1 = neuePosition;              
      }
      modeValues[mode] = encoderValue;     
    }
}

void sendMidiMsg(byte channel, byte mode, byte velocity){
  byte tmp[] = {0x0B, channel, mode, velocity};
  Serial3.write(tmp, 4);
}

void getMidiMsg(byte msg[]){
  modeValues[msg[2]] = msg[3];
}
