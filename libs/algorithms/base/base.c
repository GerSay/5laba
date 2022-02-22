#include "base.h"

/*void *maxU(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    while (size) {
        if (*pa > *pb)
            return a;
        else if (*pa < *pb)
            return b;
        else {
            pa++;
            pb++;
        }
        size--;
    }
    return a;
}*/

void *max(void *a, void *b) {
    return &a > &b ? a : b;
}

/*void *minU(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    while (size) {
        if (*pa < *pb)
            return a;
        else if (*pa > *pb)
            return b;
        else {
            pa++;
            pb++;
        }
        size--;
    }
    return a;
}*/

void *min(void *a, void *b) {
    return &a < &b ? a : b;
}

void swapU(void * const a, void * const b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa++;
        pb++;
    }
}

