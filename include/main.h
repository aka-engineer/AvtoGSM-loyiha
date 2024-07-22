#ifndef MAIN_H
#define MAIN_H

#define GSMPWR_PIN    5
#define DALLAS_PIN    25
#define SENPWR_PIN    23
#define SENBAT_PIN    36
#define SENSOL_PIN    39

#define GSMRX_PIN     18
#define GSMTX_PIN     19

#define RSXRX_PIN     26
#define RSXTX_PIN     27

#include <SoftwareSerial.h>

SoftwareSerial SerialGSM(GSMRX_PIN, GSMTX_PIN);
SoftwareSerial SerialRSX(RSXRX_PIN, RSXTX_PIN);



#endif