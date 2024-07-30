#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class ultrasonic 
{
    private:
        uint16_t _distance;

    public:
        ultrasonic();
        ~ultrasonic();
        void read();
        uint16_t getDistance();

};

#endif // ULTRASONIC_H