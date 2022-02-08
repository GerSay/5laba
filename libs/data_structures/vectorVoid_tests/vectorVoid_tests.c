#include "vectorVoid_tests.h"
#include <stdint.h>

vectorVoid v;

void test_createVectorV() {
    v = createVectorV(0, sizeof(void));
    v = createVectorV(5, sizeof(long double));
//    v = createVectorV(SIZE_MAX, sizeof(long double));
    v = createVectorV(7, sizeof(float));
    v = createVectorV(1, sizeof(char));

}