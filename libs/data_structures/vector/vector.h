#ifndef WORKPROJECT_VECTOR_H
#define WORKPROJECT_VECTOR_H

#include <stdio.h>
#include <malloc.h>

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

vector createVector(size_t n);

#endif //WORKPROJECT_VECTOR_H
