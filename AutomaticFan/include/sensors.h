#ifndef SENSORS_H
#define SENSORS_H

#include "DHT.h"

// ---- DHT ----

struct DhtSensor {
    DHT *dht;
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type);

#endif