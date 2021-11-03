#include <SoftwareSerial.h>

int state = 15;
int at = 14;

int led = 4;

int rx = 8;
int tx = 9;

int flashTime = 600;

bool BTconnected = false;

SoftwareSerial btSerial(8, 9);

char c;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(state, INPUT);
  digitalWrite(led,HIGH);
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
   if(btSerial.available())     
{
    c = btSerial.read();
    Serial.println(c);
  }
  if(Serial.available()){
    btSerial.println(Serial.read());
  }
}
