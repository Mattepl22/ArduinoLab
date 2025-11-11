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
    void (*callback)(void *); // Puntatore a funzione
    void *param; // Parametro generico
};

typedef struct Task Task;

struct TaskManager {
    Task task[MAX_TASK];
    uint8_t tCount;
    Timer timer[MAX_TASK];
};

typedef struct TaskManager TaskManager;

void taskManagerInit(TaskManager *tm);
bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long timerTrigger, bool timerMode = false);
void taskManagerRun(TaskManager *tm);

#endif