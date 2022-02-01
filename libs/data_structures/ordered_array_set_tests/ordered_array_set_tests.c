#include "../../data_structures/ordered_array_set/ordered_array_set.h"
#include "../../data_structures/bitset/bitset.h"

/*-------------------------------------------------------------------------------------*/
/*-------------Честно, я пытался сломать свой код, но, видимо, не судьба..-------------*/
/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_union1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);

    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {5}, 0);

    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6}, 6);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 0);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);

    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
    test_ordered_array_set_union4();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_in1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    size_t resIndex = ordered_array_set_in(&set1, 2);
    size_t expectedIndex = 1;

    assert(resIndex == expectedIndex);

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_in2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    size_t resIndex = ordered_array_set_in(&set1, 1);
    size_t expectedIndex = 0;

    assert(resIndex == expectedIndex);

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_in3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    size_t resIndex = ordered_array_set_in(&set1, 4);
    size_t expectedIndex = 3;

    assert(resIndex == expectedIndex);

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_in4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);

    size_t resIndex = ordered_array_set_in(&set1, 10);
    size_t expectedIndex = 4;

    assert(resIndex == expectedIndex);

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
    test_ordered_array_set_in4();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_isSubset1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 1;

    assert(result == expectedRes);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 0;

    assert(result == expectedRes);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 0);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 1;

    assert(result == expectedRes);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {5, 6}, 2);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 0;

    assert(result == expectedRes);

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
    test_ordered_array_set_isSubset4();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_insert1() {
    ordered_array_set set1 = ordered_array_set_create(10);

    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 10);
    ordered_array_set_insert(&set1, 4);
    ordered_array_set_insert(&set1, 3);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);
    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert2() {
    ordered_array_set set1 = ordered_array_set_create(10);

    ordered_array_set_insert(&set1, -1);
    ordered_array_set_insert(&set1, 3);
    ordered_array_set_insert(&set1, 14);
    ordered_array_set_insert(&set1, 0);
    ordered_array_set_insert(&set1, -8);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {-8, -1, 0, 3, 14}, 5);

    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_delete1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);

    ordered_array_set_deleteElement(&set1, 7);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 10}, 4);

    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_delete2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);

    ordered_array_set_deleteElement(&set1, 6);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);

    assert(ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_delete() {
    test_ordered_array_set_delete1();
    test_ordered_array_set_delete2();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);

    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2}, 1);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1}, 0);

    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {0}, 0);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4}, 4);

    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection4() {
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6, 7, 9, 11, 54}, 8);

    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 10);

    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2, 4, 6}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
    test_ordered_array_set_intersection4();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_difference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);

    ordered_array_set resSet =
            ordered_array_set_difference(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 3, 9}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 5}, 4);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {0, 2, 4, 6, 8}, 5);

    ordered_array_set resSet =
            ordered_array_set_difference(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {0}, 1);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    ordered_array_set resSet =
            ordered_array_set_difference(set2, set1);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 10}, 2);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 7, 8, 9}, 6);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);

    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6, 7}, 6);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);

    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 5, 6, 11}, 4);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

/*-------------------------------------------------------------------------------------*/

void test_ordered_array_set_complement1() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6, 7}, 7);

    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 6, 9}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(universumSet);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement2() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 5, 7, 9, 11}, 5);

    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 4, 6, 8, 10}, 5);

    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(universumSet);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement3() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);

    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 11);

    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);

    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 5, 7, 87, 112}, 5);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(universumSet);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
}

void test() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_delete();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}