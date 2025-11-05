#include <Arduino.h>
#include "DHT.h"

//Sensore dht
#define DHTPIN 2
#define DHTTYPE DHT11

//Led
#define RLED 4
#define GLED 5

//Dichiarazione e inizializzazione variabili
unsigned long tStart = 0;
float temperature = 0.0, soglia = 0.0;
bool readSuccesfull = false;

//Costruttore per dht
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); //Inizializzazione seriale
  
  //Inizializzazione led pins
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);

  dht.begin(); //Avvio il dht

  soglia = 30.0; //Setto la soglia

  tStart = millis(); //Salvo il momento di start
}

void loop() {

  //Ogni 2 secondi leggo la temperatura e aggiorno i led
  if (millis() - tStart > 2000) {
    temperature = dht.readTemperature(); //Lettura della temperatura

    //Se la temperatura non avviene con successo mi alzo il bit di errore
    if (isnan(temperature)) {
      readSuccesfull = false;
    } else {
      readSuccesfull = true;
    }

    //Se la lettura avviene con successo aggiorno i led
    if (temperature > 0 && temperature < soglia && readSuccesfull) {
      digitalWrite(RLED, false);
      digitalWrite(GLED, true);
    } else if (temperature >= soglia && readSuccesfull) {
      digitalWrite(GLED, false);
      digitalWrite(RLED, true);
    }

    tStart += 2000; //Aggiorno il tempo
  }

}