#ifndef UTILITY_H
#define UTILITY_H

struct Timer {
    unsigned long startTime;
    unsigned long trigger;
    bool mode;
};

typedef struct Timer Timer;

void timerInit(Timer *t, unsigned long trigger = 1, bool mode = false);
bool timerTrigger(Timer *t);
void timerReset(Timer *t);

#endif