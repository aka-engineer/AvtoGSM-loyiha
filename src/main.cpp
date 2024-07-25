#include <Arduino.h>
#include <main.h>

simcom sim(&SerialGSM, GSMPWR_PIN);

void setup() {
  Serial.begin(9600);
  SerialRSX.begin(9600);
  sim.begin();
  pinMode(GSMPWR_PIN, OUTPUT);
  digitalWrite(GSMPWR_PIN, 1);
  delay(300);
  digitalWrite(GSMPWR_PIN, 0);

}

void loop() {
  if (Serial.available()) SerialGSM.println(Serial.readStringUntil('\n'));
  if (SerialGSM.available()) Serial.println(SerialGSM.readStringUntil('\n'));
}