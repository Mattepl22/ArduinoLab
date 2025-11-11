#include <Arduino.h>

#include "taskmanager.h"

System sys;
TaskManager tm;

void setup() {
    Serial.begin(115200);

    systemInit(&sys);
    taskManagerInit(&tm);

    taskManagerAdd(&tm, dhtSensorTask, &sys, TIMER_DHT_MS, TIMER_MILLIS);
}

void loop() {
    taskManagerRun(&tm);
}
