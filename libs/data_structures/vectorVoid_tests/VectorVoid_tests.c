#include "VectorVoid_tests.h"

void test_pushBackV_getVectorValueV_1() {
    size_t n = 3;
    vectorVoid  v = createVectorV(0, sizeof(int));
    for (size_t i = 0; i < n; i++) {
        int x = i;
        pushBackV(&v, &x);
    }

    for (size_t i = 0; i < n; i++) {
        int x = i;
        getVectorValueV(&v, i, &x);

        printf("%d ", x);
    }
}

void test_pushBackV_getVectorValueV_2() {
    size_t n = 5;
    vectorVoid v = createVectorV(0, sizeof(float));
    for (size_t i = 0; i < n; i++) {
        float x = (float) 7 / i;

        pushBackV(&v, &x);
    }

    for (size_t i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }
}

void test_pushBackV_getVectorValueV() {
    test_pushBackV_getVectorValueV_1();
    test_pushBackV_getVectorValueV_2();
}