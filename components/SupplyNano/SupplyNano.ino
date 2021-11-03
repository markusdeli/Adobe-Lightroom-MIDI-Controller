#include <SoftwareSerial.h>
#include <Bounce2.h>

SoftwareSerial mySerial(3, 2); // RX, TX

int SW_DY = 6;  
int SW_SA = 7;   

bool enDY = false;
bool enSA = false;

Bounce ENC_DY = Bounce(SW_DY, 5);
Bounce ENC_SA = Bounce(SW_SA, 5);

int button1 = 10;
//int button12 = 5;

bool bb1 = false;
//bool bb12 = false;

Bounce b1 = Bounce(button1, 10);
//Bounce b12 = Bounce(button12, 10);

void setup() {
  // put your setup code here, to run once:
  pinMode(button1,INPUT_PULLUP);
//  pinMode(button12,INPUT_PULLUP);
  Serial.begin(9600);//to bt modul-
  mySerial.begin(9600);
  pinMode(SW_DY, INPUT);
  pinMode(SW_SA, INPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
}

void noteOn(byte state, byte channel, byte pitch, byte velocity) {
  byte tmp[] = {state, channel, pitch, velocity};
  mySerial.write(tmp, 4);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available() >= 4){
    byte msg[4] = {0,0,0,0};
    for(int i = 0; i < 4; i++){
      msg[i] = Serial.read();
    }
    mySerial.write(msg, 4);
  }
  if(mySerial.available() >= 4){
    byte msg[4] = {0,0,0,0};
    for(int i = 0; i < 4; i++){
      msg[i] = mySerial.read();
    }
    Serial.write(msg, 4);
  }

  if(ENC_SA.update()){
    if(!enSA){
      noteOn(3, 1, 1, 1);
      enSA = true;
    }
    else{
      enSA = false;
    }
  }
  if(ENC_DY.update()){
    if(!enDY){
      noteOn(4, 1, 1, 1);
      enDY = true;
    }
    else{
      enDY = false;
    }
  }if(b1.update()){
    if(!bb1){
      byte msg[4] = {5, 1, 10, 10};
      mySerial.write(msg, 4);
      bb1 = true; 
    }
    else{
      bb1 = false;
    }
  }
//  if(b12.update()){
    //if(!bb12){
     // byte msg[4] = {5, 12, 10, 10};
     // mySerial.write(msg, 4);
    //  bb12 = true; 
  //  }
   // else{
   //   bb12 = false;
   // }
  //}
}
