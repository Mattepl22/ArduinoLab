#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

struct Timer {
    unsigned long tStart;
    unsigned long tTrigger;
    bool mode;
};

typedef struct Timer Timer;

void timerInit(Timer *t, unsigned long tTrigger = 1, bool mode = false);
bool timerTrigger(Timer *t);

#endif