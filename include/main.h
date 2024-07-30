#ifndef MAIN_H
#define MAIN_H

#define GSMPWR_PIN    5
#define DALLAS_PIN    25
#define SENPWR_PIN    23
#define SENBAT_PIN    36
#define SENSOL_PIN    39

#define USXEN_PIN     23

#define USXRX_PIN     16
#define USXTX_PIN     17

#define GSMRX_PIN     18
#define GSMTX_PIN     19

#define RSXRX_PIN     26
#define RSXTX_PIN     27

#define SERIAL2 1

#ifdef SERIAL2
#define SerialUSX Serial2
#endif

#include <SoftwareSerial.h>
#include "simcom.h"
#include <DS18B20.h>
#include "ultrasonic.h"

#define ONE_WIRE_BUS  25

OneWire oneWire(ONE_WIRE_BUS);
DS18B20 sensor(&oneWire);



SoftwareSerial SerialGSM(GSMRX_PIN, GSMTX_PIN);
SoftwareSerial SerialRSX(RSXRX_PIN, RSXTX_PIN);



#endif