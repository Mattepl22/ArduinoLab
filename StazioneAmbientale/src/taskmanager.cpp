#include "taskmanager.h"

// ---- SYSTEM ----

void systemInit(System *sys) {

}

// ---- TASKMANAGER ----

void taskManagerInit(TaskManager *tm) {
    tm->tCount = 0;
}

bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param) {
    if (tm->tCount >= MAX_TASK) return false;

    Task *t = &tm->task[tm->tCount];
    t->callback = callback;
    t->param = param;

    //Aggiungere parte per timer per temporizzare le task

    tm->tCount++;

    return true;
}

void taskManagerRun(TaskManager *tm) {
    for (int index = 0; index < tm->tCount; index++) {
        tm->task[index].callback(tm->task[index].param);
    }
}