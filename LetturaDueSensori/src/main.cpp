#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

#define PPIN A1

unsigned long tStart_DHT = 0, tStart_POT = 0;
float temperature = 0.0, soglia = 0.0;
bool readSuccess = false;
int oldAnalogRead = 0;

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
    int valLetto = analogRead(PPIN);

    if ((valLetto > oldAnalogRead + 10) || (valLetto < oldAnalogRead - 10)) {
      Serial.println(valLetto);
      oldAnalogRead = valLetto;


    }

    tStart_POT += 5000;
  }
}