#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <Arduino.h>
#include "utility.h"

struct Task {
    void (*callback)(void *); // Funzione che devo eseguire
    void *param; // Parametro da passare
    Timer *timer;
    unsigned long interval; // Intervallo di esecuzione (ms)
    unsigned long lastRun; // Ultimo momento di esecuzione
};

typedef struct Task Task;

// Creazione del task manager

#define MAX_TASK 10

struct TaskManager {
    Task task[MAX_TASK]; // Array di task
    uint8_t taskCount; // Numero di task attive
};

typedef struct TaskManager TaskManager;

// ---- Funzioni base ----
void taskManagerInit(TaskManager *tm);
bool taskManagerAdd(TaskManager *tm, void (*callback)(void *), void *param, unsigned long interval);
void taskManagerRun(TaskManager *tm);

#endif