#include <Arduino.h>

#include "taskmanager.h"
#include "config.h"

System sys;
TaskManager tm;

void setup() {
  Serial.begin(115200);

  systemInit(&sys);
  taskManagerInit(&tm);

  taskManagerAdd(&tm, dhtSensorTask, &sys, DHT_TRIGGER, TIMER_MILLIS);
  taskManagerAdd(&tm, prSensorTask, &sys, PR_TRIGGER, TIMER_MICROS);
  taskManagerAdd(&tm, dataPrint, &sys, DATA_TRIGGER, TIMER_MILLIS);
}

void loop() {
  taskManagerRun(&tm);
}
