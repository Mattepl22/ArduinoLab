#include "utility.h"

int converter(int percValue, int IN_minValue, int IN_maxValue, int OUT_minValue, int OUT_maxValue) {
    return (percValue - IN_minValue) * ((OUT_maxValue - OUT_minValue) / (IN_maxValue - IN_minValue)) + OUT_minValue;
}