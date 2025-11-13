#ifndef SENSORS_H
#define SENSORS_H

#include "DHT.h"
#include "config.h"
#include "timer.h"

struct System;

// ---- DHT ----

struct DhtSensor {
    DHT *dht;
};

typedef struct DhtSensor DhtSensor;

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type);
void dhtSensorTask(void *param);

// ---- LED ----

void ledInit();
void ledCmd(bool bLedCmd = false, bool gLedCmd = false, bool rLedCmd = false);
void ledTask(void *param);

// ---- DC MOTOR ----

struct FanMotor {
    uint8_t pinPwm;
    uint8_t pinRun;
    uint8_t pinRev;
    int speed;
    int lastSpeed;
    Timer timer;
};

void fanMotorInit(FanMotor *fm, uint8_t pinPwm, uint8_t pinRun, uint8_t pinRev, bool direction = false);
void fanMotorDirection(FanMotor *fm, bool direction);
void fanMotorTask(void *param);

#endif