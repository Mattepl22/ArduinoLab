#include "sensors.h"
#include "taskmanager.h"

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type) {
    ds->dht = new DHT(pin, type);

    ds->dht->begin();
}

void dhtSensorTask(void *param) {
    System *sys = (System *)param;

    float temperature = sys->dhtSensor.dht->readTemperature();
    Serial.println(temperature);

    sys->data.temperature = temperature;
    sys->data.newValue = true;
}