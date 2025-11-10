#include "system.h"

// ---- SYSTEM ----

void systemInit(System *sys) {
    ledInit(&sys->led, GPIN, RPIN);
    dhtSensorInit(&sys->dhtSensor, DHTPIN, DHTTYPE, TIMER_DHT_MS, TIMER_MILLIS);
    potenziometroInit(&sys->potenziometro, PPIN, TIMER_POT_MS, TIMER_MICROS);
}

// ---- TASK ----

void taskManagerInit(TaskManager *tm) {
    tm->taskCount = 0;
}

bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param) {
    if (tm->taskCount >= MAX_TASK) return false;

    Task *t = &tm->task[tm->taskCount++];
    t->callback = callback;
    t->param = param;

    return true;
}

void taskManagerRun(TaskManager *tm) {
    for (uint8_t i = 0; i < tm->taskCount; i++) {
        Task *t = &tm->task[i];
    }
}