#ifndef FILTRO_H
#define FILTRO_H

#include "Arduino.h"

struct MediaMobile {
    int *buffer;
    int size;
    int index;
    int sum;
    bool full;
};

typedef struct MediaMobile MediaMobile;

void mediaMobileInit(MediaMobile *m, int *array, int size);
int mediaMobileUpdate(MediaMobile *m, int newValue);

#endif