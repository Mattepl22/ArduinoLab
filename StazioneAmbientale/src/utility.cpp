#include "utility.h"

void mediaMobileInit(MediaMobile *m) {
    for (int index = 0; index < MAX_INDEX; index++) {
        m->array[index] = 0;
    }

    m->full = false;
    m->count = 0;
    m->sum = 0;
}

int mediaMobileTask(MediaMobile *m, int newValue) {
    m->sum -= m->array[m->count];
    m->array[m->count] = newValue;
    m->sum += newValue;

    m->count = (m->count + 1) % MAX_INDEX;

    if (m->count == 0) m->full = true;

    int divisor = m->full ? MAX_INDEX : (m->count > 0 ? m->count : 1);

    return m->sum / divisor;
}