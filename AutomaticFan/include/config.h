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
#define BPIN 8
#define GPIN 9
#define RPIN 10

// ---- DC MOTOR ----
#define PIN_PWM 5
#define PIN_RUN 4
#define PIN_REV 3
#define IN_MIN 0
#define IN_MAX 100
#define OUT_MIN 0
#define OUT_MAX 255
#define CLOCKWISE_DIR false
#define COUNTERCLOCKWISE_DIR true

// ---- TASK ----
#define MAX_TASK 10

// ---- DATA ----
#define MAX_DATA 5


#endif