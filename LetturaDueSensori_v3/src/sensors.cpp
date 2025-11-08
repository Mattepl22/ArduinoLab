#include "sensors.h"

// TEMPERATURA + LED

// Inizializzazione della struttura per il sensore di temperatura
void dhtSensorInit(DhtSensor *s, uint8_t pin, uint8_t type, unsigned long trigger, bool mode) {
    s->pin = pin;
    s->type = type;

    s->dht = new DHT(pin, type);
    s->dht->begin();

    timerInit(&s->timer, trigger, mode);
}

// Esecuzione della task per il sensore di temperatura
void dhtSensorTask(DhtSensor *s, LedPin *l, float soglia) {

    if (timerTrigger(&s->timer)) {
        float temperature = s->dht->readTemperature();

        Serial.println(temperature);

        digitalWrite(l->pin1, temperature < soglia);
        digitalWrite(l->pin2, temperature >= soglia);
    }
}

// Inizializzazione dei led
void ledPinInit(LedPin *l, uint8_t gPin, uint8_t rPin) {
    l->pin1 = gPin;
    l->pin2 = rPin;

    pinMode(gPin, OUTPUT);
    pinMode(rPin, OUTPUT);

    digitalWrite(gPin, false);
    digitalWrite(rPin, false);
}


// POTENZIOMETRO

//Inizializzazione della struttura del potenziometro
void potenziometroInit(Potenziometro *p, uint8_t pin, unsigned long trigger, bool mode) {
    p->pin = pin;

    pinMode(pin, INPUT);

    mediaMobileInit(&p->mediaMobile, p->arrayVal, (sizeof(p->arrayVal) / sizeof(p->arrayVal[0])));
    timerInit(&p->timer, trigger, mode);
}

//Esecuzione della task del potenziometro
void potenziometroTask(Potenziometro *p) {
    if (timerTrigger(&p->timer)) {
        int newVal = mediaMobileUpdate(&p->mediaMobile, analogRead(p->pin));

        if ((newVal != p->oldAnalogRead) && p->mediaMobile.full) {
            Serial.println(newVal);
            p->oldAnalogRead = newVal;
        }
    }
}