#include <Arduino.h>

#include "system.h"
#include "config.h"

System sys;
TaskManager tasks;

void setup() {
    Serial.begin(115200);
    
    systemInit(&sys);
    taskManagerInit(&tasks);

    taskManagerAdd(&tasks, dhtTask, &sys, TIMER_DHT_MS, TIMER_MILLIS);
    taskManagerAdd(&tasks, potenziometroTask, &sys, TIMER_POT_MS, TIMER_MICROS);
}

void loop() {
    taskManagerRun(&tasks);
}