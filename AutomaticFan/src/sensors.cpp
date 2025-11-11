#include "sensors.h"

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type) {
    ds->dht = new DHT(pin, type);

    ds->dht->begin();
}