#ifndef WORKPROJECT_MATRIX_H
#define WORKPROJECT_MATRIX_H

#include "../../algorithms/array/array.h"
#include "../../algorithms/base/base.h"

typedef struct matrix {
    int **values;
    size_t nRows;
    size_t nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(size_t nRows, size_t nCols);

matrix *getMemArrayOfMatrices(size_t nMatrices, size_t nRows, size_t nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, size_t nMatrices);

void inputMatrix(matrix m);

void outputMatrix(matrix m);

void inputMatrices(matrix *ms, size_t nMatrices);

void outputMatrices(matrix *ms, size_t nMatrices);

void inputAndCreateMatrix(matrix *m);

void swapRows(matrix m, size_t i1, size_t i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (* criteria) (int *, int));

#endif //WORKPROJECT_MATRIX_H
