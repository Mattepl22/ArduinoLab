#include <Arduino.h>
#include "DHT.h"

#include "utility.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define PPIN A1

unsigned long tStart_DHT = 0, tStart_POT = 0;
float temperature = 0.0, soglia = 0.0;
bool readSuccess = false;
int oldAnalogRead = 0;
int arrayVal[10];
int arraySize = sizeof(arrayVal) / sizeof(arrayVal[0]);

DHT dht(DHTPIN, DHTTYPE);
MediaMobile filtro;

void setup() {
  Serial.begin(115200);

  pinMode(PPIN, INPUT);

  dht.begin();

  mediaMobileInit(&filtro, arrayVal, arraySize);

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

    int NewValMed = mediaMobileUpdate(&filtro, analogRead(PPIN));

    if ((NewValMed != oldAnalogRead) && filtro.full) {
      Serial.println(NewValMed);
      oldAnalogRead = NewValMed;
    }

    tStart_POT += 5000;
  }
}