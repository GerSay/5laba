#include "matrix.h"
#include <stdio.h>
#include <malloc.h>

matrix getMemMatrix(size_t nRows, size_t nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (size_t i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (size_t i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        inputArray_(m.values[i], m.nCols);
}

void outputMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        outputArray_(m.values[i], m.nCols);
//    printf("\n");
}

void inputMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrices(matrix *ms, size_t nMatrices) {
    for (size_t i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void inputAndCreateMatrix(matrix *m) {
    scanf("%d %d", &m->nRows, &m->nCols);
    *m = getMemMatrix(m->nRows, m->nCols);
    inputMatrix(*m);
}

void swapRows(matrix m, size_t i1, size_t i2) {
    swapU(m.values[i1], m.values[i2], sizeof(int) * m.nCols);
}

void swapColumns(matrix m, int j1, int j2) {
    for (size_t i = 0; i < m.nRows; i++)
        swapU(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria) (int *, int)) {
    int *newEl;
    size_t location;
    for (size_t i = 1; i < m.nRows; i++) {
        newEl = m.values[i];
        location = i;
        while(location > 0 && m.values[location - 1] > newEl) {
            m.values[location] = m.values[location - 1];
            location--;
        }
        m.values[location] = newEl;
    }
}