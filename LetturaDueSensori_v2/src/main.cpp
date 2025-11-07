#include <Arduino.h>
#include "DHT.h"

#include "utility.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define PPIN A1

#define TIMER_MILLIS false
#define TIMER_MICROS true

float temperature = 0.0, soglia = 0.0;
bool readSuccess = false;
int oldAnalogRead = 0;
int arrayVal[10];
int arraySize = sizeof(arrayVal) / sizeof(arrayVal[0]);

DHT dht(DHTPIN, DHTTYPE);
MediaMobile filtro;
Timer timer_DHT;
Timer timer_POT;

void setup() {
  Serial.begin(115200);

  pinMode(PPIN, INPUT);

  dht.begin();

  mediaMobileInit(&filtro, arrayVal, arraySize);

  timerInit(&timer_DHT, 2000, TIMER_MILLIS);
  timerInit(&timer_POT, 5000, TIMER_MICROS);
}

void loop() {

  if (timerTrigger(&timer_DHT)) {

    temperature = dht.readTemperature();
    Serial.println(temperature);
  }

  if (timerTrigger(&timer_POT)) {

    int NewValMed = mediaMobileUpdate(&filtro, analogRead(PPIN));

    if ((NewValMed != oldAnalogRead) && filtro.full) {
      Serial.println(NewValMed);
      oldAnalogRead = NewValMed;
    }
  }
}