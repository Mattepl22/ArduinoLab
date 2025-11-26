#include "dht22.h"

dht22::dht22(uint8_t dht22Pin) 
    : _dht22Pin(dht22Pin)
{}

void dht22::beginComunication() {
    pinMode(_dht22Pin, OUTPUT);
    digitalWrite(_dht22Pin, true);
    delayMicroseconds(20);
    digitalWrite(_dht22Pin, false);
    delay(1);
}

bool dht22::waitResponse() {
    pinMode(_dht22Pin, INPUT);
    unsigned long startTime = micros();
    while(micros() - startTime < )

}

