#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---- TIMER ----
#define TIMER_MILLIS false
#define TIMER_MICROS true

#define TIMER_DHT_MS 2000

// ---- DHT ----
#define DHT_PIN 13
#define DHT_TYPE DHT11

// ---- LED ----
#define BPIN 2
#define GPIN 3
#define RPIN 4

// ---- DC MOTOR ----
#define PIN_PWM 
#define PIN_RUN
#define PIN_REV

// ---- TASK ----
#define MAX_TASK 10

// ---- DATA ----
#define MAX_DATA 5


#endif