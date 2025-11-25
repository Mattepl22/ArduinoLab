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