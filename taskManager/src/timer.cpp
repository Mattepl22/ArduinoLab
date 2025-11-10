#include "timer.h"

void timerInit(Timer *t, unsigned long trigger, bool mode) {
    t->trigger = trigger;
    t->mode = mode;

    t->previousTime = mode ? micros() : millis();
}

bool timerTrigger(Timer *t) {
    if (t->trigger == 0) return false;

    unsigned long now = t->mode ? micros() : millis();

    if (now - t->previousTime > t->trigger) {
        t->previousTime += t->trigger;
    }
    
    return true;
}

void timerReset(Timer *t) {
    t->previousTime = t->mode ? micros() : millis();
}