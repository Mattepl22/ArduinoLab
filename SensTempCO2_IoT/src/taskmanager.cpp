#include "taskmanager.h"
#include <Arduino.h>

void tmInit(TaskManager *tm) {
    tm->tCount = 0;
}

bool tmAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long tTrigger, bool tMode) {
    if (tm->tCount > MAX_TASK) return false;

    Task *t = &tm->task[tm->tCount];
    t->callback = callback;
    t->param = param;

    timerInit(&tm->timer[tm->tCount], tTrigger, tMode);

    tm->tCount++;

    return true;
}

void tmRun(TaskManager *tm) {
    //Ciclo tutte le task ed eseguo solo quelle che devo eseguire
    for (int index = 0; index < tm->tCount; index++) {
        if (timerTrigger(&tm->timer[index])) {
            //Chiamo la funzione dedicata
            //La funzione si trova nella posizione index dell'array
            //".callback" è la funzione
            //".param" sono i parametri
            tm->task[index].callback(tm->task[index].param);
        }
    }
}