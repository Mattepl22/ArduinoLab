#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

#include "DHT.h"

// ---- DHT ----

struct DhtSensor {
    DHT *dht;
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t dhtPin, uint8_t dhtType); //Inizializzazione della struttura
void dhtSensorTask(void *param);

#endif