#include "simcom.h"

simcom::simcom(SoftwareSerial *serial, uint16_t pwrPin)
{
    _pwrPin = pwrPin;
    _serial = serial;
}

void simcom::begin() {
    _serial->begin(9600);
    pinMode(_pwrPin, OUTPUT);
    digitalWrite(_pwrPin, 0);
}

simcom::~simcom() {
    _serial->end();
}