#ifndef UTILITY_H
#define UTILITY_H

#include "config.h"

struct MediaMobile {
    int array[MAX_INDEX];
    int count;
    int sum;
    bool full;
};

typedef struct MediaMobile MediaMobile;

void mediaMobileInit(MediaMobile *m);
int mediaMobileTask(MediaMobile *m, int newValue);

#endif