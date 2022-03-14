#include "lr_1.1.h"

/* a) элементы множества А хранятся в массиве А. Элементы массива А не упорядочены;                                   */

static bool isFound(Set set, int val) {
    for (size_t i = 0; i < set.size; i++)
        if (set.data[i] == val)
            return 1;
    return 0;
}

static void pushback(Set* set, int val) {
    set->data[set->size] = val;
    set->size++;
}

void fPrintSet(FILE* out, Set set) {
    fprintf(out, "{");
    if (set.size) {
        for (size_t i = 0; i < set.size - 1; i++)
            fprintf(out, "%d, ", set.data[i]);
        fprintf(out, "%d", set.data[set.size - 1]);
    }
    fprintf(out, "}");
}


void unionU(Set set_1, Set set_2, Set* out_set) {
    memcpy(out_set->data, set_1.data, set_1.size * sizeof(int));
    out_set->size = set_1.size;
    for (size_t i = 0; i < set_2.size; i++)
        if (!isFound(set_1, set_2.data[i]))
            pushback(out_set, set_2.data[i]);
}

void intersectionU(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    for (size_t i = 0; i < set_2.size; i++)
        if (isFound(set_1, set_2.data[i]))
            pushback(out_set, set_2.data[i]);
}

void differenceU(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    for (size_t i = 0; i < set_1.size; i++)
        if (!isFound(set_2, set_1.data[i]))
            pushback(out_set, set_1.data[i]);
}

void xorU(Set set_1, Set set_2, Set *out_set) {
    out_set->size = 0;
    for (size_t i = 0; i < set_1.size; i++)
        if (!isFound(set_2, set_1.data[i]))
            pushback(out_set, set_1.data[i]);

    for (size_t i = 0; i < set_2.size; i++)
        if (!isFound(set_1, set_2.data[i]))
            pushback(out_set, set_2.data[i]);
}

bool isSubU(Set set_1, Set set_2) {
    for (size_t i = 0; i < set_1.size; i++)
        if (!isFound(set_2, set_1.data[i]))
            return 0;

    return 1;
}

bool areEqualU(Set set_1, Set set_2) {
    if (set_1.size != set_2.size)
        return 0;

    return isSubU(set_1, set_2);
}

void addToUniverseU(Set universe, Set set, Set* out_set) {
    differenceU(universe, set, out_set);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* b) элементы множества А хранятся в массиве А. Элементы массива А упорядочены по возрастанию;                       */

void unionO(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    size_t set_1_i = 0;
    size_t set_2_i = 0;
    while (set_1_i < set_1.size &&
           set_2_i < set_2.size)
        if (set_1.data[set_1_i] < set_2.data[set_2_i])
            pushback(out_set, set_1.data[set_1_i++]);
        else if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
            pushback(out_set, set_1.data[set_1_i++]);
            set_2_i++;
        } else
            pushback(out_set, set_2.data[set_2_i++]);

    while (set_1_i < set_1.size)
        pushback(out_set, set_1.data[set_1_i++]);
    while (set_2_i < set_2.size)
        pushback(out_set, set_2.data[set_2_i++]);
}

void intersectionO(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    size_t set_1_i = 0;
    size_t set_2_i = 0;
    while (set_1_i < set_1.size &&
           set_2_i < set_2.size)
        if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
            pushback(out_set, set_1.data[set_1_i++]);
            set_2_i++;
        } else if (set_1.data[set_1_i] < set_2.data[set_2_i])
            set_1_i++;
        else
            set_2_i++;
}

void differenceO(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    size_t set_1_i = 0;
    size_t set_2_i = 0;
    while (set_1_i < set_1.size &&
           set_2_i < set_2.size) {
        if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
            set_1_i++;
            set_2_i++;
        } else if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
            pushback(out_set, set_1.data[set_1_i++]);
        } else {
            set_2_i++;
        }
    }
    while (set_1_i < set_1.size) {
        pushback(out_set, set_1.data[set_1_i++]);
    }
}

void xorO(Set set_1, Set set_2, Set* out_set) {
    out_set->size = 0;
    size_t set_1_i = 0;
    size_t set_2_i = 0;
    while (set_1_i < set_1.size &&
           set_2_i < set_2.size) {
        if (set_1.data[set_1_i] < set_2.data[set_2_i]) {
            pushback(out_set, set_1.data[set_1_i++]);
        } else if (set_1_i == set_1.size ||
                   set_1.data[set_1_i] > set_2.data[set_2_i]) {
            pushback(out_set, set_2.data[set_2_i++]);
        } else {
            set_1_i++;
            set_2_i++;
        }
    }

    while (set_1_i < set_1.size)
        pushback(out_set, set_1.data[set_1_i++]);
    while (set_2_i < set_2.size)
        pushback(out_set, set_2.data[set_2_i++]);
}

bool isSubO(Set set_1, Set set_2) {
    size_t equal_counter = 0;
    size_t set_1_i = 0;
    size_t set_2_i = 0;
    while (set_1_i < set_1.size &&
           set_2_i < set_2.size)
        if (set_1.data[set_1_i] == set_2.data[set_2_i]) {
            set_1_i++;
            set_2_i++;
            equal_counter++;
        } else if (set_1.data[set_1_i] < set_2.data[set_2_i])
            set_1_i++;
        else
            set_2_i++;

    return equal_counter == set_1.size;
}

bool areEqualO(Set set_1, Set set_2) {
    if (set_1.size != set_2.size)
        return 0;

    return isSubO(set_1, set_2);
}

void addToUniverseO(Set universe, Set set, Set* out_set) {
    differenceO(universe, set, out_set);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* c) элементы множества А хранятся в массиве А, элементы которого типа boolean.                                      */

void fPrintBitset(FILE* out, Bitset set) {
    fprintf(out, "{");
    if (set.size) {
        for (size_t i = 0; i < set.size - 1; i++)
            if (set.data[i])
                fprintf(out, "%d, ", (int) i + 1);

        if (set.data[set.size - 1])
            fprintf(out, "%d", (int) set.size);
    }
    fprintf(out, "}");
}

void unionBitset(Bitset set_1, Bitset set_2, Bitset* out_set) {
    out_set->size = 0;
    size_t *p = max(&set_1.size, &set_2.size);
    for (size_t i = 0; i < *p; i++) {
        out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) ||
                           ((i < set_2.size) ? set_2.data[i] : 0);
        if (out_set->data[i])
            out_set->size = i + 1;
    }
}

void intersectionBitset(Bitset set_1, Bitset set_2, Bitset* out_set) {
    out_set->size = 0;
    size_t *p = min(&set_1.size, &set_2.size);
    for (size_t i = 0; i < *p; i++) {
        out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                           ((i < set_2.size) ? set_2.data[i] : 0);
        if (out_set->data[i])
            out_set->size = i + 1;
    }
}

void differenceBitset(Bitset set_1, Bitset set_2, Bitset* out_set) {
    out_set->size = 0;
    for (size_t i = 0; i < set_1.size; i++) {
        out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                           !((i < set_2.size) ? set_2.data[i] : 0);
        if (out_set->data[i])
            out_set->size = i + 1;
    }
}

void xorBitset(Bitset set_1, Bitset set_2, Bitset* out_set) {
    out_set->size = 0;
    size_t *p = max(&set_1.size, &set_2.size);
    for (size_t i = 0; i < *p; i++) {
        out_set->data[i] = ((i < set_1.size) ? set_1.data[i] : 0) &&
                           !((i < set_2.size) ? set_2.data[i] : 0) ||
                           !((i < set_1.size) ? set_1.data[i] : 0) &&
                           ((i < set_2.size) ? set_2.data[i] : 0);
        if (out_set->data[i])
            out_set->size = i + 1;
    }
}

bool isSubBitset(Bitset set_1, Bitset set_2) {
    size_t *p = max(&set_1.size, &set_2.size);
    for (size_t i = 0; i < *p; i++)
        if (((i < set_1.size) ? set_1.data[i] : 0) &&
            !((i < set_2.size) ? set_2.data[i] : 0))
            return 0;

    return 1;
}

bool areEqualBitset(const Bitset set_1, const Bitset set_2) {
    if (set_1.size != set_2.size)
        return 0;

    return isSubBitset(set_1, set_2);
}

void addToUniverseBitset(Bitset universe, Bitset set, Bitset* out_set) {
    differenceBitset(universe, set, out_set);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void outputSet(Set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; i++)
        printf("%d ", set.data[i]);
    printf("} -- Size: %d\n", set.size);
}

void task_4_1() {
    Set A = {((int[]){2, 3, 4, 5, 6}), 5};
    Set B = {((int[]){1, 2, 4, 9}), 4};
    Set C = {((int[]){4, 5, 7, 8}), 4};

    size_t totalActions = 5;
    int data_act[totalActions][MAX_SIZE];
    Set action[totalActions];
    for (size_t i = 0; i < totalActions; i++)
        action[i] = SET(data_act[i]);

    //1
    unionO(A, B, action + 0);
    outputSet(action[0]);

    //2
    xorO(B, C, action + 1);
    outputSet(action[1]);

    //3
    differenceO(C, A, action + 2);
    outputSet(action[2]);

    //4
    differenceO(action[0], action[1], action + 3);
    outputSet(action[3]);

    //5
    unionO(action[3], action[2], action + 4);

    Set D = action[4];

    printf("\nD: \n");
    outputSet(D);
    printf("\n");
}

void task_4_2() {
    Set A = {((int[]){1, 2, 4, 5, 8}), 5};
    Set B = {((int[]){2, 3, 5, 6, 9}), 5};
    Set C = {((int[]){4, 5, 6, 7, 9}), 5};

    size_t totalActions = 5;
    int data_act[totalActions][MAX_SIZE];
    Set action[totalActions];
    for (size_t i = 0; i < totalActions; i++)
        action[i] = SET(data_act[i]);

    //1
    xorO(A, C, action);
    outputSet(action[0]);

    //2
    intersectionO(A, C, action + 1);
    outputSet(action[1]);

    //3
    intersectionO(B, action[0], action +2);
    outputSet(action[2]);

    //4
    differenceO(action[1], B, action + 3);
    outputSet(action[3]);

    //5
    unionO(action[3], action[2], action + 4);

    Set D = action[4];

    printf("\nD: \n");
    outputSet(D);
    printf("\n");
}
