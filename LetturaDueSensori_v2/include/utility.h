#ifndef UTILITY_H
#define UTILITY_H

#include <Arduino.h>

// -------- MEDIA MOBILE --------

struct MediaMobile{
    int *buffer;
    int size;
    int index;
    int sum;
    bool full;
};

typedef struct MediaMobile MediaMobile;

void mediaMobileInit(MediaMobile *m, int *array, int size); //Inizializzo i valori della media mobile
int mediaMobileUpdate(MediaMobile *m, int newValue); //Aggiorno la media mobile

// ------------------------------

#endif