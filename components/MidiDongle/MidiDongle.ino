#include <SoftwareSerial.h>
#include <MIDIUSB.h>

int state = 15;
int at = 14;

int rx_led_pin = 17;

int led = 9;

//int rx = 9;
//int tx = 8;

int flashTime = 600;

bool BTconnected = false;

byte msg[4] = {0,0,0,0};

//SoftwareSerial btSerial(8, 9);

char c;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(state, INPUT);
  pinMode(rx_led_pin, OUTPUT);
  digitalWrite(led,HIGH);
}

void fillMidiMessage(byte bytes[]){
    midiEventPacket_t tmp = { bytes[0], bytes[1], bytes[2], bytes[3] };
    MidiUSB.sendMIDI(tmp);
}

void printHex(uint8_t num){
  char hexChar[2];
  sprintf(hexChar, "%02X", num);
  Serial.println(hexChar);
}

void sendMidiMsg(){
  midiEventPacket_t tmp = MidiUSB.read();
  if(tmp.byte3 != 0){
    byte midiBytes[] = {0x0b, tmp.byte1, tmp.byte2, tmp.byte3};
    Serial1.write(midiBytes, 4);
  }
}

void loop() {
  while (!BTconnected)
    {
      digitalWrite(led, HIGH);
      delay(flashTime);
      digitalWrite(led, LOW);
      delay(flashTime);
      if ( digitalRead(state)==HIGH) 
      { 
        BTconnected = true;
        digitalWrite(led, HIGH);
        }
    }
  if (digitalRead(state) ==LOW){
    BTconnected = false;
  }

   if(Serial1.available() == 4){
    for (int i=0; i<4; i++){
      msg[i] = Serial1.read();
    }
    fillMidiMessage(msg);
    MidiUSB.flush();
   }
   
    sendMidiMsg();
    for(int i=0; i<4; i++){
      msg[i] = 0;
    }

    if(digitalRead(LED_BUILTIN_TX) == HIGH){
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
}
