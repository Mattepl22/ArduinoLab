#ifndef SENSORS_H
#define SENSORS_H

#include "utility.h"
#include "DHT.h"
#include "config.h"

// TEMPERATURA + LED
struct DhtSensor{
    DHT *dht;
    uint8_t pin;
    uint8_t type;
    Timer timer;
};

struct LedPin{
    uint8_t pin1;
    uint8_t pin2;
};

typedef struct DhtSensor DhtSensor;
typedef struct LedPin LedPin;

//Inizializzazione della struttura del sensore. 
//In questa struttura inizializzo anche il timer che mi servirà per eseguire la task in maniera temporizzata.
void dhtSensorInit(DhtSensor *s, uint8_t pin, uint8_t type, unsigned long trigger, bool mode=false);
void dhtSensorTask(DhtSensor *s, LedPin *l, float soglia); //Task temporizzata. Accende anche i led

void ledPinInit(LedPin *l, uint8_t gPin, uint8_t rPin); //Inizializzazione dei pin dei led

// POTENZIOMETRO
struct Potenziometro{
    uint8_t pin;
    MediaMobile mediaMobile;
    Timer timer;
    int oldAnalogRead;
    int arrayVal[DIMENSIONE_BUFFER];
};

typedef struct Potenziometro Potenziometro;

//Inizializzazione della struttura del potenziometro. 
//In questa struttura inizializzo anche il timer che mi servirà per eseguire la task in maniera temporizzata.
//Inizializzo anche la media mobile per filtrare i dati
void potenziometroInit(Potenziometro *p, uint8_t pin, unsigned long trigger, bool mode=false);
void potenziometroTask(Potenziometro *p); //Task temporizzata e con media mobile

#endif