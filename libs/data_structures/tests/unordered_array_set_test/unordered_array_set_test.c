#include <assert.h>

#include "unordered_array_set_test.h"
#include "../../bitset/bitset.h"
#include "../../unordered_array_set/unordered_array_set.h"

void test_unordered_array_set_create1() {
    unordered_array_set set1 = unordered_array_set_create(3);
    assert(set1.size == 0);
    assert(set1.capacity == 3);
}

void test_unordered_array_set_create2() {
    unordered_array_set set1 = unordered_array_set_create(2);
    assert(set1.size == 0);
    assert(set1.capacity == 2);
}

void test_unordered_array_set_create3() {
    unordered_array_set set1 = unordered_array_set_create(10);
    assert(set1.size == 0);
    assert(set1.capacity == 10);
}

void test_unordered_array_set_create() {
    test_unordered_array_set_create1();
    test_unordered_array_set_create2();
    test_unordered_array_set_create3();
}

void test_unordered_array_set_in1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);
    int value = 1;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 0;

    assert (resSet == index);
}

void test_unordered_array_set_in2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 3, 2, 1, 0}, 5);
    int value = 0;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 6;

    assert (resSet == index);
}

void test_unordered_array_set_in3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-50, 57, 42, 0, 12, 87}, 7);
    int value = 2;
    long long resSet = unordered_array_set_in(&set1, value);
    int index = 5;

    assert (resSet == index);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
}

void test_unordered_array_set_isEqual1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1, 2}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;

    assert (resSet == expectedRes);
}

void test_unordered_array_set_isEqual2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 3, 2}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3, 1}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;

    assert (resSet == expectedRes);
}

void test_unordered_array_set_isEqual3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 4, 6}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 9}, 3);

    bool resSet = unordered_array_set_isEqual(set1, set2);
    bool expectedRes = true;

    assert (resSet == expectedRes);
}

void test_unordered_array_set_isEqual() {
    test_unordered_array_set_isEqual1();
    test_unordered_array_set_isEqual2();
    test_unordered_array_set_isEqual3();
}

void test_unordered_array_set_insert1() {
    unordered_array_set set1 = unordered_array_set_create(3);
    unordered_array_set_insert(&set1, 6);
    unordered_array_set_insert(&set1, -1);
    unordered_array_set_insert(&set1, 4);

    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {17, -109, 64}, 3);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set1 = unordered_array_set_create(2);
    unordered_array_set_insert(&set1, 9);
    unordered_array_set_insert(&set1, 10);

    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {9, 10}, 2);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert3() {
    unordered_array_set set1 = unordered_array_set_create(1);
    unordered_array_set_insert(&set1, 0);

    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {42}, 1);

    assert(unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
    test_unordered_array_set_insert3();
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 1}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {-1, -2, -3}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-1, 2, -3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, -2, 3}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, -2, -3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, -4, 1, -2}, 4);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 4, 6, 8, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 7, 9}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {4, 6, 12, 2, -3, 0, 44}, 7);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, -15, 2}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {-5}, 1);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-3, 4, 22, 8, 4}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
}


void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {0, 3, 5, 6}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {5, 1, 2}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {0, 3, 6}, 3);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {63, 3, 4, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {0, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {63, 5}, 2);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 1, -4, 5, 7, 9}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 3}, 5);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1}, 1);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {5, 6, 7, 1, 2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-4, 5, 7, 9, 3}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, -4, 6, 2, 9, 3}, 6);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3, 5, 10}, 4);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference3() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {-4, -5, 5, 6, -2}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {-2, 6, 5, -5, -4}, 5);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {}, 0);

    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
    test_unordered_array_set_symmetricDifference3();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3, 2, 4, 5, 6, 8}, 7);
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == 6);
    assert(resSet.data[1] == 8);
    assert(resSet.size == 2);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
}

void test_unordered_array_set_complement2() {
    int a1[] = {4, 7, 8, 9, 1};
    unordered_array_set set1 = {a1, 5, 10};
    int a2[] = {4, 8, 9, 1, 7, -3, -4, 0};
    unordered_array_set set2 = {a2, 8, 10};
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == -3);
    assert(resSet.data[1] == -4);
    assert(resSet.data[2] == 0);
    assert(resSet.size == 3);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
}

void test_unordered_array_set_complement3() {
    int a1[] = {9, 0, 2};
    unordered_array_set set1 = {a1, 3, 5};
    int a2[] = {2, 0, 9, -1};
    unordered_array_set set2 = {a2, 4, 5};
    unordered_array_set resSet = unordered_array_set_complement(set1, set2);

    assert(resSet.data[0] == -1);
    assert(resSet.size == 1);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
}


void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
}

void tests() {
    test_unordered_array_set_in();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_create();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
    test_unordered_array_set_insert();
}