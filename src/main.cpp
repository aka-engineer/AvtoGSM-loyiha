#include <Arduino.h>
#include <main.h>
#include <stdio.h>

simcom sim(&SerialGSM, GSMPWR_PIN);

void setup() {
  Serial.begin(115200);
  SerialRSX.begin(9600);
  sim.begin();
  sensor.begin();
  sensor.setResolution(10);
  pinMode(GSMPWR_PIN, OUTPUT);
  pinMode(USXEN_PIN, OUTPUT);
  digitalWrite(GSMPWR_PIN, 1);
  delay(300);
  digitalWrite(GSMPWR_PIN, 0);
  pinMode(USXRX_PIN, OUTPUT);
  pinMode(USXTX_PIN, OUTPUT);
  digitalWrite(USXEN_PIN, 0);
}

uint32_t last_time = 0;

void loop() {
  if (Serial.available()) SerialGSM.println(Serial.readStringUntil('\n'));
  if (SerialGSM.available()) Serial.println(SerialGSM.readStringUntil('\n'));
  if (millis() - last_time > 1000) 
  {
    last_time = millis();
    sensor.requestTemperatures();
    while (!sensor.isConversionComplete()) {
      delay(10);
    }
    Serial.printf("Temperature: %.2f\n", sensor.getTempC());
  }
}