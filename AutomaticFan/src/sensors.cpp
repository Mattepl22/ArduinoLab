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

    Serial.println(sys->data.temperature);

    if (!sys->data.newValue) return;

    if (sys->data.temperature <= 20.0) {
        ledCmd(true, false, false);
    } else if ((sys->data.temperature > 20.0) && (sys->data.temperature <= 25.0)) {
        ledCmd(false, true, false);
    } else {
        ledCmd(false, false, true);
    }
}