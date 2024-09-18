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
    int8_t powerON();
    int8_t powerOFF();
    int8_t httpGET(const char* url, const char* data, uint16_t datalen);
    int8_t httpPOST(const char* url, const char* data, uint16_t datalen);
    int8_t setAPN(const char*);
    int8_t attachGPRS();
    int8_t detachGPRS();
    int8_t attachGPS();
    int8_t detachGPS();
    int8_t getGPSInfo(char* gpsData);
    int8_t getIP(char* ipAddress);
    int8_t getIMEI(char* imei);
    int8_t getBATInfo(bool volt_percent=false); /* If true retur voltage in millivolts else percent */
    int8_t getRSSI();
    int8_t sendSMS(const char* number, const char* message);
    void handle();
};


#endif