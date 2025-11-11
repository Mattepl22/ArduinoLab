#include "sensor.h"
#include "system.h"

// ---- LED ----

void ledInit(Led *l, uint8_t greenPin, uint8_t redPin) {
    l->greenPin = greenPin;
    l->redPin = redPin;

    digitalWrite(greenPin, false);
    digitalWrite(redPin, false);
}

void ledCmd(Led *l, bool greenPin_state, bool redPin_state) {
    digitalWrite(l->greenPin, greenPin_state);
    digitalWrite(l->redPin, redPin_state);
}

// ---- DHT ----

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type) {
    ds->dht = new DHT(pin, type);
    ds->dht->begin();
}

void dhtTask(void *param) {
    System *sys = (System *)param;

    float temperature = sys->dhtSensor.dht->readTemperature();
    Serial.println(temperature);
    ledCmd(&sys->led, temperature <= SOGLIA_TEMPERATURA, temperature > SOGLIA_TEMPERATURA);
}

// ---- POTENZIOMETRO ----

void potenziometroInit(Potenziometro *p, uint8_t pin) {
    p->pin = pin;
    p->oldValue = 0;

    pinMode(pin, INPUT);

    mediaMobileInit(&p->mediaMobile, p->arrayVal, sizeof(p->arrayVal) / sizeof(p->arrayVal[0]));
}

void potenziometroTask(void *param) {
    System *sys = (System *)param;

    int newValue = mediaMobileUpdate(&sys->potenziometro.mediaMobile, analogRead(sys->potenziometro.pin));

    if((newValue != sys->potenziometro.oldValue) && sys->potenziometro.mediaMobile.full) {
        Serial.println(newValue);
        sys->potenziometro.oldValue = newValue;
    }
}