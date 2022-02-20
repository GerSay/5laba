#include "matrix.h"

void errorSquareMatrix() {
    fprintf(stderr, "Matrix is not square");
    exit(4);
}

void errorIndexMatrix(indexR, indexC) {
    fprintf(stderr, "position [%d][%d] outside the array.\n", indexR, indexC);
    exit(2);
}

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

//---------------------------------------1-----------------------------------

void swapRowsSquareMatrixWithMaxMinElement(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

//---------------------------------------2-----------------------------------

int getMax(int *a, size_t n) {
    int max = a[0];
    for (size_t i = 0; i < n; i++)
        max = max < a[i] ? a[i] : max;

    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//---------------------------------------3-----------------------------------

int getMin(int *a, size_t n) {
    int min = a[0];
    for (size_t i = 0; i < n; i++)
        min = min > a[i] ? a[i] : min;

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//---------------------------------------4-----------------------------------

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows)
        errorSquareMatrix();

    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (size_t iRow = 0; iRow < m1.nRows; iRow++)
        for (size_t iCol = 0; iCol < m2.nCols; iCol++) {
            m.values[iRow][iCol] = 0;
            for (size_t i = 0; i < m1.nCols; i++)
                m.values[iRow][iCol] += m1.values[iRow][i] * m2.values[i][iCol];
        }

    return m;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

//---------------------------------------5-----------------------------------

size_t find(long long *arr, size_t size, int element) {
    for (size_t i = 0; i < size; i++)
        if (arr[i] == element)
            return i;

    return size;
}

bool isUnique(long long *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        const size_t pos = find(arr, size, (int) arr[i]);
        if (pos != i && pos != size)
            return 0;
    }

    return 1;
}

long long getSum(int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m, size_t nRows, size_t nCols) {
    long long *rSum = malloc(m.nRows * sizeof(long long));
    for (size_t i = 0; i < m.nRows; i++)
        rSum[i] = getSum(m.values[i], m.nCols);

    if (isUnique(rSum, m.nRows))
        transposeSquareMatrix(m);
}

//---------------------------------------6-----------------------------------

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isSquareMatrix(m1) && isEMatrix(mulMatrices(m1, m2));
}

/*int test_MutuallyInverseMatrices() {
    size_t n;
    scanf("%zu", &n);

    matrix m1 = getMemMatrix(n, n);
    inputMatrix(m1);
    matrix m2 = getMemMatrix(n, n);
    inputMatrix(m2);

    printf("%d", isMutuallyInverseMatrices(m1, m2));

    return 0;
}*/

//---------------------------------------7-----------------------------------

int max(int a, int b) {
    return a > b ? a : b;
}

int findDiagonalMax(matrix m, size_t i, size_t k) {
    size_t iRow = i;
    size_t iCol = k;
    int max = m.values[iRow][iCol];
    while (iCol < m.nCols && iRow < m.nRows) {
        if (m.values[iRow][iCol] > max)
            max = m.values[iRow][iCol];
        iRow++;
        iCol++;
    }

    return max;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (size_t iShift = m.nRows - 1; iShift > 0; iShift--)
        sum += findDiagonalMax(m, iShift, 0);

    for (size_t kShift = 1; kShift < m.nCols; kShift++)
        sum += findDiagonalMax(m, 0, kShift);

    return sum;
}

//---------------------------------------8-----------------------------------

int min(int x, int y) {
    return x < y ? x : y;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);
    int minEl = m.values[maxPos.rowIndex][maxPos.colIndex];
    for (size_t iRow = maxPos.rowIndex; iRow != -1; iRow--) {
        const size_t dist = maxPos.rowIndex - iRow;
        const size_t start = max(0, (int)(maxPos.colIndex - dist));
        const size_t end = min((int)m.nCols - 1, (int)(maxPos.colIndex + dist));
        minEl = getMin(m.values[iRow] + start, end - start + 1);
    }

    return minEl;
}

//---------------------------------------9-----------------------------------

float getDistance(int *a, size_t n) {
    float distance = 0;
    for (size_t i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, size_t)) {
    float rowsCriteria[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (size_t i = 1; i < m.nRows; i++)
        for (size_t j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swapU(&rowsCriteria[j - 1], &rowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

//---------------------------------------10----------------------------------

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    return arg1 > arg2;
}

int countNUnique(long long *a, size_t n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int counterOfUnique = 1;
    size_t i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }

    return counterOfUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (size_t i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}

//---------------------------------------11----------------------------------

