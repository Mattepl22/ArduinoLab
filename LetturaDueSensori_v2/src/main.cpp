#include <Arduino.h>
#include "sensors.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define PPIN A1

#define GPIN 6
#define RPIN 8

#define TIMER_MILLIS false
#define TIMER_MICROS true

float temperature = 0.0, soglia = 0.0;
bool readSuccess = false;
int oldAnalogRead = 0;
int arrayVal[20];
int arraySize = sizeof(arrayVal) / sizeof(arrayVal[0]);

DhtSensor dhtSensor;
LedPin led;
MediaMobile filtro;
Timer timer_DHT;
Timer timer_POT;

void setup() {
  Serial.begin(115200);

  pinMode(PPIN, INPUT);

  mediaMobileInit(&filtro, arrayVal, arraySize);
  dhtSensorInit(&dhtSensor, DHTPIN, DHTTYPE);
  ledPinInit(&led, GPIN, RPIN);
  
  soglia = 25.0;

  timerInit(&timer_DHT, 2000, TIMER_MILLIS);
  timerInit(&timer_POT, 5000, TIMER_MICROS);
}

void loop() {

  if (timerTrigger(&timer_DHT)) dhtSensorTask(&dhtSensor, &led, soglia);

  if (timerTrigger(&timer_POT)) potenziometroTask(PPIN, &filtro, &oldAnalogRead);
}