#include <Arduino.h>

#include "taskmanager.h"
#include "comunication.h"

Data data;
System sys;
TaskManager tm;

void setup() {
    Serial.begin(115200);

    systemInit(&sys);
    dataInit(&data);
    taskManagerInit(&tm);

    sys.data = &data;

    taskManagerAdd(&tm, dhtSensorTask, &sys, TIMER_DHT_MS, TIMER_MILLIS);
}

void loop() {
    taskManagerRun(&tm);
}
