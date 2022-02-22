#ifndef WORKPROJECT_MATRIX_H
#define WORKPROJECT_MATRIX_H

#include "../../algorithms/array/array.h"
#include "../../algorithms/base/base.h"

#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct matrix {
    int **values;
    size_t nRows;
    size_t nCols;
} matrix;

typedef struct position {
    size_t rowIndex;
    size_t colIndex;
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

void swapColumns(matrix m, size_t j1, size_t j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (* criteria) (int *, size_t));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, size_t));

bool isSquareMatrix(matrix m);

bool isTwoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

void transposeMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);


#endif //WORKPROJECT_MATRIX_H
