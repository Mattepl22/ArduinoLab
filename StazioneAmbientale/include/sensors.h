#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

#include "DHT.h"
#include "utility.h"

// ---- DHT ----

struct DhtSensor {
    DHT *dht;
    bool newValue;
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t dhtPin, uint8_t dhtType); //Inizializzazione della struttura
void dhtSensorTask(void *param);

// ---- PHOTO RESISTOR ----

struct PrSensor {
    uint8_t prPin;
    int maxValue;
    MediaMobile mediaMobile;
    bool newValue;
};

typedef struct PrSensor PrSensor;

void prSensorInit(PrSensor *ps, uint8_t pin, int maxValue);
void prSensorTask(void *param);

#endif