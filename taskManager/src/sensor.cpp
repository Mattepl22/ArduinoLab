#include "sensor.h"

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

void dhtSensorInit(DhtSensor *ds, uint8_t pin, uint8_t type, unsigned long timerTrig, bool timerMode = false) {
    ds->dht = new DHT(pin, type);
    ds->dht->begin();

    timerInit(&ds->timer, timerTrig, timerMode);
}

void dhtSensorTask(DhtSensor *ds, Led *l, float soglia) {
    if (timerTrigger(&ds->timer)) {
        float temperature = ds->dht->readTemperature();

        Serial.println(temperature);

        ledCmd(l, temperature <= soglia, temperature > soglia);
    }
}

// ---- POTENZIOMETRO ----

void potenziometroInit(Potenziometro *p, uint8_t pin, unsigned long timerTrig, bool timerMode = false) {
    p->pin = pin;
    p->oldValue = 0;

    mediaMobileInit(&p->mediaMobile, p->arrayVal, sizeof(p->arrayVal) / sizeof(p->arrayVal[0]));
    timerInit(&p->timer, timerTrig, timerMode);
}

void potenziometroUpdate(Potenziometro *p) {
    if (timerTrigger(&p->timer)) {
        int newValue = analogRead(p->pin);
        
        if ((newValue != p->oldValue) && p->mediaMobile.full) {
            Serial.println(newValue);
            p->oldValue = newValue;
        }
    }
}