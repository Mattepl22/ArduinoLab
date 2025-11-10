#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Configurazioni DHT11
#define DHTPIN 2
#define DHTTYPE DHT11

// Configurazioni LED
#define GPIN 6
#define RPIN 8

// Configurazioni POTENZIOMETRO
#define PPIN A1

// Configurazioni per funzionamento timer
#define TIMER_MILLIS false
#define TIMER_MICROS true

// Dimensione buffer
const uint8_t DIMENSIONE_BUFFER = 20;
const uint8_t MAX_TASK = 10;

// Costanti e soglie
const unsigned long TIMER_DHT_MS = 2000;
const unsigned long TIMER_POT_MS = 10000;
const float SOGLIA_TEMPERATURA = 25.0;

#endif