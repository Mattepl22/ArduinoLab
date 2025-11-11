#include "taskmanager.h"

// ---- SYSTEM ----
void systemInit(System *sys) {
    dhtSensorInit(&sys->dhtSensor, DHT_PIN, DHT_TYPE);
}

// ---- TASK MANAGER ----

void taskManagerInit(TaskManager *tm) {
    tm->tCount = 0;
}