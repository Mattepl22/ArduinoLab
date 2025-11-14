#include "timer.h"

void timerInit(Timer *t, unsigned long tTrigger, bool mode) {
    t->tTrigger = tTrigger;
    t->mode = mode;

    t->tStart = mode ? micros() : millis();
}

bool timerTrigger(Timer *t) {
    int now = t->mode ? micros() : millis();

    if ((now - t->tStart) >= t->tTrigger) {
        t->tStart += t->tTrigger;
        return true;
    }

    return false;
}