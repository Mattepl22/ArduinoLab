#include "taskmanager.h"

// Inizializzazione del task manager
void taskManagerInit(TaskManager *tm) {
    tm->taskCount = 0;
}

// Aggiunta di una task
bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long interval) {
    if (tm->taskCount >= MAX_TASK) return false; // Limite massimo di task raggiunto

    Task *t = &tm->task[tm->taskCount++];
    t->callback = callback;
    t->param = param;
    t->interval = interval;
    t->lastRun = millis();

    return true;
}

// Esecuzione ciclica delle task
void taskManagerRun(TaskManager *tm) {
    for (uint8_t i = 0; i < tm->taskCount; i++) {
        Task *t = &tm->task[i];

        if(timerTrigger(t->timer)) {
            t->callback(t->param); // Eseguo la funzione
        }
    }
}