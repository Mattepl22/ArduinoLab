#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define PPIN A1

int mediaMobileCircolare(int *array, int arraySize, int *indexScrittura, int newValue, int *sum, bool *bufferFull) {

  *sum -= array[*indexScrittura];
  array[*indexScrittura] = newValue;
  *sum += newValue;
  
  *indexScrittura = (*indexScrittura + 1) % (arraySize);

  if (*indexScrittura == 0) {
    *bufferFull = true;
  }

  return *sum/arraySize;
}

unsigned long tStart_DHT = 0, tStart_POT = 0;
float temperature = 0.0, soglia = 0.0;
bool readSuccess = false, bufferFull = false;
int oldAnalogRead = 0, indexScrittura = 0, sum = 0;
int arrayVal[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int arraySize = sizeof(arrayVal) / sizeof(arrayVal[0]);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  pinMode(PPIN, INPUT);

  dht.begin();

  tStart_DHT = millis();
  tStart_POT = micros();
}

void loop() {
  if (millis() - tStart_DHT >= 2000) {
    temperature = dht.readTemperature();

    Serial.println(temperature);

    tStart_DHT += 2000;
  }

  if (micros() - tStart_POT >= 5000) {

    int NewValMed = mediaMobileCircolare(arrayVal, arraySize, &indexScrittura, analogRead(PPIN), &sum, &bufferFull);

    if ((NewValMed != oldAnalogRead) && bufferFull) {
      Serial.println(NewValMed);
      oldAnalogRead = NewValMed;
    }

    tStart_POT += 5000;
  }
}