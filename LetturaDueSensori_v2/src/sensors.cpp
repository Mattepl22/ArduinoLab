#include "sensors.h"

// TEMPERATURA + LED

void dhtSensorInit(DhtSensor *s, uint8_t pin, uint8_t type) {
    s->pin = pin;
    s->type = type;

    s->dht = new DHT(pin, type);
    s->dht->begin();
}

void dhtSensorTask(DhtSensor *s, LedPin *l, float soglia) {
    float temperature = s->dht->readTemperature();

    Serial.println(temperature);

    digitalWrite(l->pin1, temperature < soglia);
    digitalWrite(l->pin2, temperature >= soglia);
    
}

void ledPinInit(LedPin *l, uint8_t gPin, uint8_t rPin) {
    l->pin1 = gPin;
    l->pin2 = rPin;

    pinMode(gPin, OUTPUT);
    pinMode(rPin, OUTPUT);

    digitalWrite(gPin, false);
    digitalWrite(rPin, false);
}


// POTENZIOMETRO

void potenziometroTask(uint8_t pin, MediaMobile *m, int *oldAnalogRead) {
    int newVal = mediaMobileUpdate(m, analogRead(pin));

    if ((newVal != *oldAnalogRead) && m->full) {
        Serial.println(newVal);
        *oldAnalogRead = newVal;
    }
}