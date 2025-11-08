#ifndef SENSORS_H
#define SENSORS_H

#include "utility.h"
#include "DHT.h"

// TEMPERATURA + LED
struct DhtSensor{
    DHT *dht;
    uint8_t pin;
    uint8_t type;
};

struct LedPin{
    uint8_t pin1;
    uint8_t pin2;
};

typedef struct DhtSensor DhtSensor;
typedef struct LedPin LedPin;

void dhtSensorInit(DhtSensor *s, uint8_t pin, uint8_t type, unsigned long trigger, bool mode = false);
void dhtSensorTask(DhtSensor *s, LedPin *l, float soglia);

void ledPinInit(LedPin *l, uint8_t gPin, uint8_t rPin);

// POTENZIOMETRO

void potenziometroTask(uint8_t pin, MediaMobile *m, int *oldAnalogRead);


#endif