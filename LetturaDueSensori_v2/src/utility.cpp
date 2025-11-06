#include "utility.h"

// MEDIA MOBILE

void mediaMobileInit(MediaMobile *m, int *array, int size) {
    m->buffer = array;
    m->size = size;
    m->index = 0;
    m->sum = 0;
    m->full = false;

    for (int i = 0; i < size; i++) {
        m->buffer[i] = 0;
    }
}

int mediaMobileUpdate(MediaMobile *m, int newValue) {
    m->sum -= m->buffer[m->index]; //Aggiorno il valore somma
    m->buffer[m->index] = newValue; //Aggiungo il valore
    m->sum += newValue; //Aggiorno la somma

    m->index = (m->index + 1) % m->size; //Incremendo l'indice con modulo

    if (m->index == 0) {
        m->full = true;
    }

    int divisor = m->full ? m->size : m->index;

    return m->sum/divisor;
}