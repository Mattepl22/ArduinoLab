#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>

#include "config.h"

// ---- SYSTEM ----

struct System {

};

typedef struct System System;

void systemInit(System *sys);

// ---- TASKMANAGER ----

struct Task {
    void (*callback)(void *);
    void *param;
};

struct TaskManager {
    Task task[MAX_TASK];
    uint8_t tCount;
};

typedef struct Task Task;
typedef struct TaskManager TaskManager;

void taskManagerInit(TaskManager *tm);
bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param);
void taskManagerRun(TaskManager *tm);

#endif