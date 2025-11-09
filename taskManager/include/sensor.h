#ifndef SENSOR_H
#define SENSOR_h

#include <Arduino.h>
#include "DHT.h"
#include "timer.h"

// ---- LED ----

struct Led {
    uint8_t greenPin;
    uint8_t redPin;
};

typedef struct Led Led;

void ledInit(Led *l, uint8_t greenPin, uint8_t redPin);
void ledCmd(Led *l, bool greenPin_state, bool redPin_state);

// ---- DHT ----

struct DhtSensor {
    DHT *dht;
    Timer timer;
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type, unsigned long timerTrig, bool timerMode = false);
void dhtSensorTask(DhtSensor *ds, Led *l, float soglia);

#endif