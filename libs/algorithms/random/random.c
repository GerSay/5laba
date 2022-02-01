#define RAND_A 16807
#define RAND_M 0x7fffffff

unsigned long long lcg(long long seed) {
    return seed * RAND_A % RAND_M;
}

#include "random.h"