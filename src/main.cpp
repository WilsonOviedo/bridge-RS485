#include <Arduino.h>

//#include <SoftwareSerial.h>

// SoftwareSerial Serial2(7, 8); // RX, TX

#define DE_RE 33  // Pin de control DE/DE
#define BAUD 300 // Velocidad de RS485

#define ECHO false

void preTrans()
{
  digitalWrite(DE_RE, HIGH);
}
void posTrans()
{
  digitalWrite(DE_RE, LOW);
}


void setup()
{
  pinMode(DE_RE, OUTPUT);
  posTrans();
  Serial.begin(9600, SERIAL_7E1);
  // Serial.begin(BAUD);
  while (!Serial)
  {
    ;
  }
  Serial2.begin(BAUD, SERIAL_7E1);
  Serial.write("Start!...");
  preTrans();
  Serial2.write("/?02745281!\r\n");
  Serial2.flush();
  posTrans();
}

void loop()
{
  
while (Serial2.available())
  {
    Serial.write(Serial2.read());
  }
}