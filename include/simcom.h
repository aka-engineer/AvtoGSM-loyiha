#ifndef SIMCOM_H
#define SIMCOM_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/FreeRTOSConfig.h>

class simcom
{
private:
    SoftwareSerial *_serial;
    char* _readData;
    uint16_t _battVoltage;
    uint8_t _battPercent;
    uint8_t _rssi;
    uint8_t _response(const char*);
    TaskFunction_t response();
    uint16_t _pwrPin;

public:
    simcom(SoftwareSerial *serial, uint16_t pwrPin);
    ~simcom();
    int8_t begin();
    int8_t powerdown();
    int8_t powerup();
    int8_t httpGET(const char*);
    int8_t httpPOST(const char*);

};


#endif