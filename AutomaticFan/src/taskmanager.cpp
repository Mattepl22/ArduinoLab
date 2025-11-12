#include "taskmanager.h"

// ---- SYSTEM ----
void systemInit(System *sys) {
    dhtSensorInit(&sys->dhtSensor, DHT_PIN, DHT_TYPE);
    dataInit(&sys->data);
}

// ---- TASK MANAGER ----

void taskManagerInit(TaskManager *tm) {
    tm->tCount = 0;
}

bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long timerTrigger, bool timerMode) {
    if (tm->tCount > MAX_TASK) return false;

    Task *t = &tm->task[tm->tCount];
    t->callback = callback;
    t->param = param;

    if (timerTrigger != 0) {
        timerInit(&tm->timer[tm->tCount], timerTrigger, timerMode);
    }

    tm->tCount++;

    return true;
}

void taskManagerRun(TaskManager *tm) {
    for (int index = 0; index < tm->tCount; index++) {
        if (timerTrigger(&tm->timer[index])) {
            tm->task[index].callback(tm->task[index].param);
        }
    }
}