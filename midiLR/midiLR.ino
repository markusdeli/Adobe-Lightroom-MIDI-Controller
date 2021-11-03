#include <MIDIUSB.h>
#include <Encoder.h>

const int CLK = 9;     
const int DT = 8;
const int SW = 7;       // on an Interrupt pin
const int BUTTON_ONE = 2;
const int BUTTON_TWO = 3;

long position1 = -999;
int encoderValue; 
Encoder myEnc(DT,CLK);
bool state = false;

int mode = 0;
const int modeLimit = 48;
int modeValues[modeLimit] = { 64 };

midiEventPacket_t event = {0x0B, 0xB0, 0x00, 0x00};

void Interrupt(){
  mode ++;
  Serial.print("MODE ->");
  Serial.println(mode);
}

void sendMidiMsg(byte mode, byte velocity){
  midiEventPacket_t tmp = event;
  tmp.byte2 = mode;
  tmp.byte3 = velocity;
  MidiUSB.sendMIDI(tmp);
  MidiUSB.flush();
}

void readLightroomValues(){
  midiEventPacket_t tmp = MidiUSB.read();
  if(tmp.byte2 >= 0 && tmp.byte2 <= modeLimit){
    if(tmp.byte3 != 0){
      Serial.print("MODE ->");
      Serial.print(tmp.byte2);
      Serial.print("    ");
      Serial.print("VELO ->");
      Serial.println(tmp.byte3);
      modeValues[tmp.byte2] = tmp.byte3;
    }
  }
}

//TODO
void readButtons(){
  if(digitalRead(BUTTON_ONE) == 0){
  }
  else if(digitalRead(BUTTON_TWO) == 0){
  }   
  else if(digitalRead(BUTTON_ONE) == 0 && digitalRead(BUTTON_TWO) == 0){
  }        
  else if(digitalRead(BUTTON_ONE) == 0 && state){
  }  
  else if(digitalRead(state && digitalRead(BUTTON_TWO)) == 0){    
  }  
  else if(digitalRead(BUTTON_ONE) == 0 && digitalRead(BUTTON_TWO) == 0 && state){   
  }
}

void readEncoder(){    
  long neuePosition; 
  encoderValue = modeValues[mode];
  neuePosition = myEnc.read();  
    if (neuePosition != position1)  // Sollte die neue Position ungleich der alten (-999) sein (und nur dann!!)...
    {
      if (neuePosition > position1 + 3){
        if(encoderValue < 127){
          encoderValue++;
        }           
        sendMidiMsg(mode, encoderValue);            
        position1 = neuePosition;  
      }
      else if(neuePosition < position1 - 3){
        if(encoderValue > 0){              
          encoderValue--;
        }
        sendMidiMsg(mode, encoderValue);            
        position1 = neuePosition;              
      }
      modeValues[mode] = encoderValue;     
    }
}

void setup() {
  Serial.begin(115200);     
  pinMode(SW, INPUT);   // Hier wird der Interrupt installiert.
  pinMode(BUTTON_ONE,INPUT_PULLUP);
  pinMode(BUTTON_TWO,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SW), Interrupt, RISING);
}

void loop() {
  readLightroomValues();
  readEncoder();
  readButtons();
}
