#include "filtro.h"

void mediaMobileInit(MediaMobile *m, int *array, int size) {
    m->buffer = array;
    m->size = size;
    m->index = 0;
    m->sum = 0;
    m->full = false;

    for (int index = 0; index < size; index++) {
        m->buffer[index] = 0;
    }
}

int mediaMobileUpdate(MediaMobile *m, int newValue) {
    m->sum -= m->buffer[m->index];
    m->buffer[m->index] = newValue;
    m->sum += newValue;

    m->index = (m->index + 1) % m->size; // Incremento con modulo

    if (m->index == 0) {
        m->full = true;
    }

    int divisor = m->full ? m->size : (m->index == 0 ? 1 : m->index);

    return m->sum/divisor;
}