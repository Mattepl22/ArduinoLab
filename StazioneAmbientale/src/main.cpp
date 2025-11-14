#include <Arduino.h>

#include "taskmanager.h"
#include "config.h"

System sys;
TaskManager tm;

void setup() {
  Serial.begin(115200);

  systemInit(&sys);
  taskManagerInit(&tm);
}

void loop() {
  taskManagerRun(&tm);
}
