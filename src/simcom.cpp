#include "simcom.h"

simcom::simcom(SoftwareSerial *serial, uint16_t pwrPin)
{
    _pwrPin = pwrPin;
    _serial = serial;
}

int8_t simcom::begin() {
    _serial->begin(9600);
    pinMode(_pwrPin, OUTPUT);
    digitalWrite(_pwrPin, 1);
    delay(500);
    digitalWrite(_pwrPin, 0);
    return 0;
}

simcom::~simcom() {
    _serial->end();
}

int8_t simcom::powerON() {
    return 0;
}

int8_t simcom::powerOFF() {
    digitalWrite(_pwrPin, 1);
    delay(2000);
    digitalWrite(_pwrPin, 0);
    while (!_serial->available());
    if (_serial->readStringUntil('\n').indexOf("NORMAL POWER DOWN") == 0) return 0;
    else return -1;
}

int8_t simcom::httpGET(const char* url, const char* data, uint16_t datalen) {
    
    return 0;
}