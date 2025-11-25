#include "utility.h"
#include <Arduino.h>

void timerInit(Timer *t, unsigned long trigger, bool mode) {
    t->trigger = trigger;
    t->mode = mode;

    t->startTime = mode ? micros() : millis();
}

bool timerTrigger(Timer *t) {
    //Leggo il tempo attuale a seconda della modalità
    unsigned long now = t->mode ? micros() : millis();

    //Controllo se è passato il tempo e ritorno true in caso affermativo
    if (now - t->startTime >= t->trigger) {
        t->startTime += t->trigger;
        return true;
    }

    return false;
}

void timerReset(Timer *t) {
    //Reset del timer
    t->startTime += t->trigger;
}