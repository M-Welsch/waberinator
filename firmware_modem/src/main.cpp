#include <Arduino.h>
#include <HardwareSerial.h>

#include <EEPROM.h>
#include <LittleFS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <NeoPixelBus.h>


HardwareSerial SerialPort(2);


void setup() {
  Serial.begin(38400);
  SerialPort.begin(38400, SERIAL_8N1, 18, 17);
}

void loop() {
  Serial.println("Bla0");
  SerialPort.println("Bla1");
  sleep(1);
}
