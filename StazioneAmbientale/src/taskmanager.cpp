#include "taskmanager.h"

// ---- COMUNICATION ----

void dataInit(Data *d) {
    d->temperature = 0.0;
    d->humidity = 0.0;
}

void dataPrint(void *param){
    System *sys = (System *)param;

    Serial.print("{temperature: ");
    Serial.print(sys->data.temperature);
    Serial.print("; humidity: ");
    Serial.print(sys->data.humidity);
    Serial.println("}");
}

// ---- SYSTEM ----

void systemInit(System *sys) {
    dhtSensorInit(&sys->dhtSensor, DHT_PIN, DHT_TYPE);
    dataInit(&sys->data);
}

// ---- TASKMANAGER ----

void taskManagerInit(TaskManager *tm) {
    tm->tCount = 0;
}

bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long tTrigger, bool tMode) {
    if (tm->tCount >= MAX_TASK) return false;

    Task *t = &tm->task[tm->tCount];
    t->callback = callback;
    t->param = param;

    timerInit(&tm->timer[tm->tCount], tTrigger, tMode);

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
