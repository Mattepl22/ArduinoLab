#include "system.h"

// ---- SYSTEM ----

void systemInit(System *sys) {
    ledInit(&sys->led, GPIN, RPIN);
    dhtSensorInit(&sys->dhtSensor, DHTPIN, DHTTYPE);
    potenziometroInit(&sys->potenziometro, PPIN);
}

// ---- TASK ----

void taskManagerInit(TaskManager *tm) {
    tm->taskCount = 0;
}

bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long timerTrigger, bool timerMode) {
    if (tm->taskCount >= MAX_TASK) return false;

    Task *t = &tm->task[tm->taskCount];
    t->callback = callback;
    t->param = param;

    timerInit(&tm->timer[tm->taskCount++], timerTrigger, timerMode);

    return true;
}

void taskManagerRun(TaskManager *tm) {
    for (uint8_t i = 0; i < tm->taskCount; i++) {
        if (timerTrigger(&tm->timer[i])) {
            tm->task[i].callback(tm->task[i].param);
        }
    }
}