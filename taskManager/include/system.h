#ifndef SYSTEM_H
#define SYSTEM_H

#include "sensor.h"

// ---- SYSTEM ----

struct System {
    Led led;
    DhtSensor dhtSensor;
    Potenziometro potenziometro;
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
    uint8_t taskCount;
    Timer timer;
};

typedef struct TaskManager TaskManager;

void taskManagerInit(TaskManager *tm);
bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param);
void taskManagerRun(TaskManager *tm);

#endif