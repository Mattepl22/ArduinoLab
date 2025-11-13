#include "sensors.h"
#include "taskmanager.h"

// ---- DHT ----

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type) {
    ds->dht = new DHT(pin, type);

    ds->dht->begin();
}

void dhtSensorTask(void *param) {
    System *sys = (System *)param;

    float temperature = sys->dhtSensor.dht->readTemperature();
    //Serial.println(temperature);

    sys->data.temperature = temperature;
    sys->data.newValue = true;
}

// ---- LED ----

void ledInit() {
    pinMode(BPIN, OUTPUT);
    digitalWrite(BPIN, false);

    pinMode(GPIN, OUTPUT);
    digitalWrite(GPIN, false);

    pinMode(RPIN, OUTPUT);
    digitalWrite(RPIN, false);
}

void ledCmd(bool bLedCmd, bool gLedCmd, bool rLedCmd) {
    digitalWrite(BPIN, bLedCmd);
    digitalWrite(GPIN, gLedCmd);
    digitalWrite(RPIN, rLedCmd);
}

void ledTask(void *param) {
    System *sys = (System *)param;

    if (!sys->data.newValue) return;

    if (sys->data.temperature <= 20.0) {
        ledCmd(true, false, false);
    } else if ((sys->data.temperature > 20.0) && (sys->data.temperature <= 25.0)) {
        ledCmd(false, true, false);
    } else {
        ledCmd(false, false, true);
    }
}

// ---- DC MOTOR ----

void fanMotorInit(FanMotor *fm, uint8_t pinPwm, uint8_t pinRun, uint8_t pinRev, bool direction) {
    fm->pinPwm = pinPwm;
    fm->pinRun = pinRun;
    fm->pinRev = pinRev;

    pinMode(pinPwm, OUTPUT);
    pinMode(pinRun, OUTPUT);
    pinMode(pinRev, OUTPUT);


    fanMotorDirection(fm, direction);
    analogWrite(pinPwm, 0);
}

// Scrivo la direzione sui pin della direzione
void fanMotorDirection(FanMotor *fm, bool direction) {
    digitalWrite(fm->pinRun, !direction);
    digitalWrite(fm->pinRev, direction);
}

void fanMotorTask(void *param) {
    System *sys = (System *)param;

    
}