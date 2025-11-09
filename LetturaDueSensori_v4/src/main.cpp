#include <Arduino.h>
#include "system.h"
#include "taskmanager.h"

Sistema sistema;
TaskManager manager;

void setup() {
  Serial.begin(115200);

  sistemaInit(&sistema);
  taskManagerInit(&manager);

  taskManagerAdd(&manager, dhtTask, &sistema, TIMER_DHT_MS);
  taskManagerAdd(&manager, potTask, &sistema, TIMER_POT_MS);
}

void loop() {

  taskManagerRun(&manager);

}