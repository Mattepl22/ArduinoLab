#include "system.h"

void dhtTask(void *param) {
    System *sys = (System *)param;

    float temperature = sys->dhtSensor.dht->readTemperature();
    Serial.println(temperature);
    ledCmd(&sys->led, temperature <= SOGLIA_TEMPERATURA, temperature > SOGLIA_TEMPERATURA);
}

void potenziometroTask(void *param) {
    System *sys = (System *)param;

    int newValue = mediaMobileUpdate(&sys->potenziometro.mediaMobile, analogRead(sys->potenziometro.pin));

    if((newValue != sys->potenziometro.oldValue) && sys->potenziometro.mediaMobile.full) {
        Serial.println(newValue);
        sys->potenziometro.oldValue = newValue;
    }
}