#include "sensors.h"
#include "taskmanager.h"

// ---- DHT ----

void dhtSensorInit(DhtSensor *ds, uint8_t dhtPin, uint8_t dhtType) {
    
    ds->dht = new DHT(dhtPin, dhtType);
    ds->dht->begin();
}

void dhtSensorTask(void *param) {
    System *sys = (System *)param;
    
    float temp = sys->dhtSensor.dht->readTemperature();
    float hum = sys->dhtSensor.dht->readHumidity();

    if (!isnan(temp)) sys->data.temperature = temp;
    if (!isnan(hum)) sys->data.humidity = hum;
}

// ---- PHOTO RESISTOR ----

void prSensorInit(PrSensor *ps, uint8_t pin) {
    
    ps->prPin = pin;
    pinMode(pin, INPUT);
    
    mediaMobileInit(&ps->mediaMobile);
}

void prSensorTask(void *param) {
    System *sys = (System *)param;

    int value = mediaMobileTask(&sys->prSensor.mediaMobile, analogRead(sys->prSensor.prPin));
    
    if (sys->prSensor.mediaMobile.full) {
        sys->data.light = value;
    }
}