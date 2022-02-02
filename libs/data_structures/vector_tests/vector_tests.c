#include "../../algorithms/algorithms.h"
#include "vector_tests.h"


//--89-
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);
    assert(v.size == 1);
    assert(v.data[0] == 5);
}

//--90-
void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = v.capacity;
    pushBack(&v, 5);

    assert(v.size == 6);
    assert(v.data[v.size - 1] == 5);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    v.size = 5;
    v.data[0] = 5;
    assert(v.data == atVector(&v, 0));
}

void test_atVectorRequestToLastElement() {
    vector v = createVector(5);
    v.size = 5;
    v.data[5] = 5;
    assert(v.data + 4 == atVector(&v, 4));
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 42;
    assert(&v.data[v.size - 1] == back(&v));
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    v.data[0] = 42;
    assert(&v.data[0] == front(&v));
}

