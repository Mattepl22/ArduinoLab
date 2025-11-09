#ifndef SYSTEM_H
#define SYSTEM_H

#include "sensors.h"
#include "config.h"

struct Sistema{
    DhtSensor dhtSensor;
    LedPin ledPin;
    Potenziometro potenziometro;
};

typedef struct Sistema Sistema;

void sistemaInit(Sistema *s);

#endif