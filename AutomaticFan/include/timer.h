#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

struct Timer {
    unsigned long previousTime;
    unsigned long trigger;
    bool mode;
};

typedef struct Timer Timer;

void timerInit(Timer *t, unsigned long trigger = 1, bool mode = false);
bool timerTrigger(Timer *t);
void timerReset(Timer *t);

#endif