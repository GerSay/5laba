#include "DiscMath.h"

int *varFirst(int *a, size_t sizeA, int *b, size_t sizeB, int *c, size_t *sizeC) {
    size_t lastEl = 0;
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeA; j++)
            if (a[i] == a[j] && i != j)
                flag = 0;

        if (flag)
            c[lastEl++] = a[i];
    }
    for (size_t i = 0; i < sizeB; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeB; j++)
            if (b[i] == b[j] && i != j)
                flag = 0;

        if (flag)
            c[lastEl++] = b[i];
    }
    *sizeC = lastEl;

    return c;
}

int *varSecond(int *a, size_t sizeA, int *b, size_t sizeB, int *c, size_t *sizeC) {
    size_t lastEl = 0;
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 0;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 1;

        if (flag)
            c[lastEl++] = a[i];
    }
    *sizeC = lastEl;

    return c;
}

int *varThird(int *a, size_t sizeA, int *b, size_t sizeB, int *c, size_t *sizeC) {
    size_t lastEl = 0;
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 0;

        if (flag)
            c[lastEl++] = a[i];
    }
    *sizeC = lastEl;

    return c;
}

int *varFour(int *a, size_t sizeA, int *b, size_t sizeB, int *c, size_t *sizeC) {
    size_t lastEl = 0;
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 0;

        if (flag)
            c[lastEl++] = a[i];
    }
    for (size_t i = 0; i < sizeB; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeA; j++)
            if (b[i] == a[j])
                flag = 0;

        if (flag)
            c[lastEl++] = b[i];
    }
    *sizeC = lastEl;

    return c;
}

int varFive(int *a, size_t sizeA, int *b, size_t sizeB) {
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 0;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 1;
        if (!flag)
            return 0;
    }

    return 1;
}

int varSix(int *a, size_t sizeA, int *b, size_t sizeB) {
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 0;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 1;
        if (!flag)
            return 0;
    }
    for (size_t i = 0; i < sizeB; i++) {
        int flag = 0;
        for (size_t j = 0; j < sizeA; j++)
            if (b[i] == a[j])
                flag = 1;
        if (!flag)
            return 0;
    }

    return 1;
}

int varSeven(int *a, size_t sizeA, int *b, size_t sizeB) {
    for (size_t i = 0; i < sizeA; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeB; j++)
            if (a[i] == b[j])
                flag = 0;
        if (!flag)
            return 0;
    }
    for (size_t i = 0; i < sizeB; i++) {
        int flag = 1;
        for (size_t j = 0; j < sizeA; j++)
            if (b[i] == a[j])
                flag = 0;
        if (!flag)
            return 0;
    }

    return 1;
}

int *varEight(int *a, size_t sizeA, int *b, size_t sizeB, int *c, size_t *sizeC) {
    size_t iA = 0, iB = 0;
    *sizeC = 0;
    for (size_t i = 0; i < sizeA + sizeB; i++)
        if (a[iA] < b[iB] && iA <= sizeA) {
            c[*sizeC] = a[iA];
            iA++;
            (*sizeC)++;
        } else if (a[iA] == b[iB]) {
            c[*sizeC] = a[iA];
        }

}