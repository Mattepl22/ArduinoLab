#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "config.h"
#include "utility.h"

// ---- SYSTEM ----

struct System {

};

typedef struct System System;

void systemInit(System *sys);

// ---- TASK ----

struct Task {
    void (*callback)(void *);
    void *param;
};

typedef struct Task Task;

struct TaskManager {
    Task task[MAX_TASK];
    Timer timer[MAX_TASK];
    int tCount;
};

typedef struct TaskManager TaskManager;

void tmInit(TaskManager *tm);
bool tmAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long tTrigger = 1, bool tMode = false);
void tmRun(TaskManager *tm);


#endif