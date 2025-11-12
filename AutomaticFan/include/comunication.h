#ifndef COMUNICATION_H
#define COMUNICATION_H

#include "config.h"

// ---- STRUTTURA DATI ----

struct Data {
    float temperature;
    bool newValue;
};

typedef struct Data Data;

void dataInit(Data *d); //Funzione inizializzazione struttura dati

#endif