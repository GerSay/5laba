#include "vector_tests.h"

vector v;

void test_createVector() {
    v = createVector(0);
    assert(v.data == NULL);
    clear(&v);
}

void test_createVectorError() {
    v = createVector(SIZE_MAX);
}

void test_reserve() {
    v = createVector(5);
    reserve(&v, 0);
    assert(v.data == NULL);

    v.capacity = 5;
    v.size = 5;
    reserve(&v, 3);
    assert(v.size == 3);
}

void test_reserve_error() {
    reserve(&v, SIZE_MAX);
}

void test_clear() {
    v = createVector(5);
    v.size = v.capacity;
    clear(&v);
    assert(v.size == 0);
}

void test_shrinkToFit() {
    v = createVector(5);
    v.size = 3;
    shrinkToFit(&v);
    assert(v.capacity == v.size);
}

void test_isEmpty() {
    v = createVector(5);
}

void test_pushBack_emptyVector() {
    v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
    assert(v.data[0] == 5);
}

void test_pushBack_fullVector() {
    v = createVector(5);
    v.size = v.capacity;
    pushBack(&v, 5);

    assert(v.size == 6);
    assert(v.data[v.size - 1] == 5);
}

void test_popBack_notEmptyVector() {
    v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    v = createVector(5);
    v.size = 5;
    v.data[0] = 5;
    assert(v.data == atVector(&v, 0));
}

void test_atVectorRequestToLastElement() {
    v = createVector(5);
    v.size = 5;
    v.data[5] = 5;
    assert(v.data + 4 == atVector(&v, 4));
}

void test_back_oneElementInVector() {
    v = createVector(1);
    v.size = 1;
    v.data[0] = 42;
    assert(&v.data[v.size - 1] == back(&v));
}

void test_front_oneElementInVector() {
    v = createVector(1);
    v.size = 1;
    v.data[0] = 42;
    assert(&v.data[0] == front(&v));
}

void test_vector() {
    test_createVector();
    test_reserve();
    test_clear();
    test_shrinkToFit();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVectorRequestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}