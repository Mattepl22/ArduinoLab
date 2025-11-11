#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "sensors.h"
#include "timer.h"
#include "config.h"

// ---- SYSTEM ----

struct System {
    DhtSensor dhtSensor;
};

typedef struct System System;

void systemInit(System *sys);

// ---- TASK MANAGER ----

struct Task {
    void (*callback)(void *);
    Timer timer;
};

typedef struct Task Task;

struct TaskManager {
    Task task[MAX_TASK];
    uint8_t tCount;
};

typedef struct TaskManager TaskManager;

void taskManagerInit(TaskManager *tm);
bool taskManagerAdd(TaskManager *tm);

#endif