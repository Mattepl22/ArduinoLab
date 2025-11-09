#include "system.h"

void sistemaInit(Sistema *s) {
    dhtSensorInit(&s->dhtSensor, DHTPIN, DHTTYPE, TIMER_DHT_MS, TIMER_MILLIS);
    ledPinInit(&s->ledPin, GPIN, RPIN);
    potenziometroInit(&s->potenziometro, PPIN, TIMER_POT_MS, TIMER_MICROS);
}