#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "DHT.h"
#include "timer.h"
#include "filtro.h"
#include "config.h"

struct System;

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
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type);
void dhtTask(void *param);

// ---- POTENZIOMETRO ----

struct Potenziometro {
    uint8_t pin;
    int arrayVal[DIMENSIONE_BUFFER];
    int oldValue;
    MediaMobile mediaMobile;
};

typedef struct Potenziometro Potenziometro;

void potenziometroInit(Potenziometro *p, uint8_t pin);
void potenziometroTask(void *param);

#endif