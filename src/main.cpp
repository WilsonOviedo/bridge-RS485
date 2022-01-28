#include <Arduino.h>

//#include <SoftwareSerial.h>


//SoftwareSerial Serial2(7, 8); // RX, TX

#define DE_RE 33 //Pin de control DE/DE
#define BAUD 300 //Velocidad de RS485

void preTrans(){
  digitalWrite(DE_RE,HIGH);
}
void posTrans(){
  digitalWrite(DE_RE,LOW);
}
void setup() {
  pinMode(DE_RE,OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  Serial2.begin(BAUD);
}

void loop() { 
    
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
  while(Serial.available()) {
    preTrans();
    Serial2.write(Serial.read());    
  }
  Serial2.flush();
  posTrans();
  
}
