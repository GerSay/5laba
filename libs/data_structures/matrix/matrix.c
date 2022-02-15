#include "matrix.h"

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

void swapColumns(matrix m, size_t j1, size_t j2) {
    for (size_t i = 0; i < m.nRows; i++)
        swapU(&m.values[i][j1], &m.values[i][j2], sizeof(int));
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, size_t)) {
    int rowsCriteria[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], (int) m.nCols);

    for (size_t i = 1; i < m.nRows; i++)
        for (size_t j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swapU(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(int));
            swapRows(m, j, j - 1);
        }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, size_t)) {
    int colsCriteria[m.nCols];
    for (size_t j = 0; j < m.nCols; j++) {
        int colsEl[m.nRows];
        for (size_t i = 0; i < m.nRows; i++)
            colsEl[i] = m.values[i][j];

        colsCriteria[j] = criteria(colsEl, (int) m.nRows);
    }

    for (size_t i = 1; i < m.nCols; i++)
        for (size_t j = i; j > 0 && colsCriteria[j - 1] > colsCriteria[j]; j--) {
            swapU(&colsCriteria[j - 1], &colsCriteria[j], sizeof(int));
            swapColumns(m, j, j - 1);
        }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows == m2.nRows && m1.nCols == m2.nCols) {
        for (size_t i = 0; i < m1.nRows; i++)
            if ((bool) memcmp(m1.values[i], m2.values[i], m1.nCols))
                return 0;
        return 1;
    }
    return 0;
}

bool isEMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (size_t i = 0; i < m.nRows; i++)
            for (size_t j = 0; j < m.nCols; j++)
                if (i == j && m.values[i][j] != 1 ||
                    i != j && m.values[i][j])
                    return 0;
        return 1;
    }
    return 0;
}

bool isSymmetricMatrix(matrix m) {
    if (isSquareMatrix(m)) {
        for (size_t i = 0; i < m.nRows; i++)
            for (size_t j = 0; j < m.nCols; j++)
                if (m.values[i][j] != m.values[j][i])
                    return 0;
        return 1;
    }
    return 0;
}

void transposeSquareMatrix(matrix m) {
    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            swapU(&m.values[i][j], &m.values[j][i], sizeof(int));
}

void transposeMatrix(matrix *m) {
    for (size_t i = 0; i < m->nRows; i++)
        for (size_t j = 0; j < m->nRows; j++)
            swapU(&m->values[i][j], &m->values[j][i], sizeof(int));
    swapU(&m->nRows, &m->nCols, sizeof(size_t));
}

position getMinValuePos(matrix m) {
    int min = m.values[0][0];
    position p = {0, 0};

    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                p.colIndex = j;
                p.rowIndex = i;
            }

    return p;
}

position getMaxValuePos(matrix m) {
    int max = m.values[0][0];
    position p = {0, 0};

    for (size_t i = 0; i < m.nRows; i++)
        for (size_t j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max) {
                max = m.values[i][j];
                p.colIndex = j;
                p.rowIndex = i;
            }

    return p;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    size_t k = 0;
    for (size_t i = 0; i < nRows; i++)
        for (size_t j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

/*void test_countZeroRows() {
    matrix m = createMatrixFromArray (
            (int[]) {
        1, 1, 0,
        0, 0, 0,
        0, 0, 1,
        0, 0, 0,
        0, 1, 1,
    },
    5, 3
    );

    assert(countZeroRows(m, 5, 3) == 2);

    freeMemMatrix(m);
}*/

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices,
                                     size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    size_t l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

void swapRowsSquareMatrixWithMaxMinElement(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

int getMax(int *a, size_t n) {
    int max = a[0];
    for (size_t i = 0; i < n; i++)
        max = max < a[i] ? a[i] : max;

    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, size_t n) {

    int min = a[0];
    for (size_t i = 0; i < n; i++)
        min = min > a[i] ? a[i] : min;

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

