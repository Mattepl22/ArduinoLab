#include "sensors.h"
#include "taskmanager.h"

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
