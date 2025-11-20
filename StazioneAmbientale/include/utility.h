#ifndef UTILITY_H
#define UTILITY_H

#include "config.h"

// ---- MEDIA MOBILE ----

struct MediaMobile {
    int array[MAX_INDEX];
    int count;
    int sum;
    bool full;
};

typedef struct MediaMobile MediaMobile;

void mediaMobileInit(MediaMobile *m);
int mediaMobileTask(MediaMobile *m, int newValue);

// ---- SCALATURA ----

struct Scala {
    int minIn;
    int maxIn;
    int minOut;
    int maxOut;
};

typedef struct Scala Scala;

void scalaInit(Scala *s, int minIn, int maxIn);
int scalaToPerc(Scala *s, int value);

#endif