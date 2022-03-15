#ifndef WORKPROJECT_5CTASKS_H
#define WORKPROJECT_5CTASKS_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <memory.h>

#include "../../../libs/algorithms/base/base.h"
#include "../../../libs/algorithms/array/array.h"
#include "../../../libs/algorithms/algorithms.h"


#define BITS_TEP 8
#define NUMBER_STEP 255
#define SEAD 10000
#define BUFFER_SIZE 100000
#define COUNT_REPEAT 10

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
        clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
    }

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

#define DECREASE_FACTOR 1.24733


typedef struct SortFunc {
    void (*sort )(int *a, size_t n);
    char name[64];
} SortFunc;

typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n);
    char name[64];
} GeneratingFunc;

typedef struct number {
    int number;
    int key;
} number;


void timeExperiment();

#endif //WORKPROJECT_5CTASKS_H
