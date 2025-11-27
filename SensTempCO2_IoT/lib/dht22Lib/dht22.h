#ifndef DHT22_H
#define DHT22_H

#include <Arduino.h>

class dht22 {
    private:
        // Variabili private
        uint8_t _dht22Pin;

        void beginComunication();
        bool waitResponse();

    public:
        dht22(uint8_t dht22Pin);
        float readTemperature();
        int readHumidity();
};

#endif