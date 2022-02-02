#include "vector.h"


void error() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    vector v;
    v.size = 0;
    v.capacity = n;
    v.data = malloc(sizeof(int) * v.capacity);
    if (v.data == NULL)
        error();
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL)
        error();
    if (newCapacity == 0 && v->capacity != 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve (v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size < v->capacity)
        v->data[v->size++] = x;
    else
        reserve(v, v->capacity * 2);
}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    printf("%d", v.data[v.size]);
}

int main() {
    test_pushBack_emptyVector();

    return 0;
}



