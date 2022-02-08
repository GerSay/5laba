#ifndef WORKPROJECT_VECTORVOID_H
#define WORKPROJECT_VECTORVOID_H

#include <stdio.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;



#endif //WORKPROJECT_VECTORVOID_H
