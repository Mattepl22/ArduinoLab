#include <Arduino.h>
#include "system.h"

Sistema sistema;

void setup() {
  Serial.begin(115200);

  sistemaInit(&sistema);
}

void loop() {

  dhtSensorTask(&sistema.dhtSensor, &sistema.ledPin, SOGLIA_TEMPERATURA);

 potenziometroTask(&sistema.potenziometro);
}