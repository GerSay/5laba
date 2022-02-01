#include <malloc.h>

#include "ordered_array_set.h"

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) { malloc(sizeof(int) * capacity), 0, capacity};
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      const size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    return set;
}

bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;
    return !memcmp(set1.data, set2.data, set1.size);
}

bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
    if (subset.size == 0)
        return true;

    size_t indexFirst = binarySearch_(set.data, set.size, subset.data[0]);
    size_t i = 0;
    size_t j = indexFirst;

    while (i < subset.size && j < set.size)
        if (set.data[j] < set.data[i])
            j++;
        else
            i++;

    return i == subset.size;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");

    bool isEmpty = true;
    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", set.data[i]);
        isEmpty = false;
    }

    if (isEmpty)
        printf("}");
    else
        printf("\b\b}");
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLess(set->data, set->size, value);
        if (positionInsert == -1)
            insert_(set->data, &set->size, 0, value);
        else
            insert_(set->data, &set->size, positionInsert + 1, value);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) != set->size) {
        size_t indexDelete = binarySearch_(set->data, set->size, value);
        deleteByPosSaveOrder_(set->data, &set->size, indexDelete);
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);
    size_t i = 0;
    size_t j = 0;

    while (j < set2.size && i < set1.size) {
        if (set2.data[j] < set1.data[i])
            append_(set3.data, &set3.size, set2.data[j++]);
        else if (set2.data[j] > set1.data[i])
            append_(set3.data, &set3.size, set1.data[i++]);
        else
            j++;
    }

    while (j < set2.size)
        append_(set3.data, &set3.size, set2.data[j++]);
    while (i < set1.size)
        append_(set3.data, &set3.size, set1.data[i++]);

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1,
                                                 ordered_array_set set2) {
    size_t capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);
    size_t i = 0;
    size_t j = 0;

    while (i < set1.size && j < set2.size)
        if (set1.data[i] > set2.data[j])
            j++;
        else if (set1.data[i] < set2.data[j])
            i++;
        else {
            append_(set3.data, &set3.size, set1.data[i++]);
            j++;
        }

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1,
                                               ordered_array_set set2) {
    size_t i = 0;
    size_t j = 0;
    int capacity = set1.size + set2.size;
    ordered_array_set set3 = ordered_array_set_create(capacity);

    while (i < set1.size && j < set2.size)
        if (set1.data[i] < set2.data[j])
            append_(set3.data, &set3.size, set1.data[i++]);
        else if (set1.data[i] == set2.data[j])
            i++;
        else
            j++;

    for (size_t k = i; k < set1.size; k++)
        append_(set3.data, &set3.size, set1.data[k]);

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1,
                                                        ordered_array_set set2) {
    return (ordered_array_set) ordered_array_set_union(ordered_array_set_difference(set1, set2),
                                                       ordered_array_set_difference(set2, set1));
}

ordered_array_set ordered_array_set_complement(ordered_array_set set,
                                               ordered_array_set universumSet) {
    return (ordered_array_set) ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

