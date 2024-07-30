#include "simcom.h"

simcom::simcom(SoftwareSerial *serial, uint16_t pwrPin)
{
    _pwrPin = pwrPin;
    _serial = serial;
}

int8_t simcom::begin() {
    _serial->begin(9600);
    pinMode(_pwrPin, OUTPUT);
    digitalWrite(_pwrPin, 0);
    return 0;
}

simcom::~simcom() {
    _serial->end();
}

int8_t simcom::powerdown() {
    return 0;
}

int8_t simcom::powerup() {

    return 0;
}

int8_t simcom::httpGET(const char* url) {
    
    return 0;
}