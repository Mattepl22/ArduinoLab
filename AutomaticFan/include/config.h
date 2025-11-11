#ifndef CONFIG_H
#define CONFIG_h

#include <Arduino.h>

// ---- TIMER ----
#define TIMER_MILLIS false
#define TIMER_MICROS true

unsigned long TIMER_DHT_MS = 2000;

// ---- DHT ----
#define DHT_PIN 2
#define DHT_TYPE DHT11


#endif