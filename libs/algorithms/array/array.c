#include "array.h"

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert (pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? UINT_MAX : pos;

        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        n[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

int binarySearchLess(int *a, int size, int x) {
    int l = -1;
    int r = size;
    while (r > l + 1) {
        int middle = l + (r - l) / 2;
        if (a[middle] > x)
            r = middle;
        else if (a[middle] <= x)
            l = middle;
    }
    return l;
}

size_t binarySearchIf_(const int *a, size_t n, int x, int (*f) (int, int)) {
    size_t left = 0;
    size_t right = n - 1;
    while (right > left + 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return UINT_MAX;
}

void copyArray(int *a, const int *b, size_t size) {
    for (size_t i = 0; i < size; i++)
        a[i] = b[i];
}

int compare_ints(void *a, void *b) {
    return (*(char *) a - *(char *) b);
}


void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos + 1; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int any_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int all_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate )(
        int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;

}

void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return UINT_MAX;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {

    if (a[0] >= x)
        return 0;
    size_t left = 0;

    size_t right = n;
    while (right - left > 1) {

        size_t middle = left + (right - left) / 2;

        if (a[middle] < x)
            left = middle;
        else
            right = middle;

    }
    return right;
}

void inputArrayD_(int *m, size_t size) {
    for (size_t i = 0; i < size; i++)
        scanf("%d", m + i);
}

int _getMax(int *a, size_t n) {
    int max = a[0];
    for (size_t i = 0; i < n; i++)
        max = max < a[i] ? a[i] : max;

    return max;
}

int _getMin(int *a, size_t n) {
    int min = a[0];
    for (size_t i = 0; i < n; i++)
        min = min > a[i] ? a[i] : min;

    return min;
}

size_t _find(long long *arr, size_t size, int element) {
    for (size_t i = 0; i < size; i++)
        if (arr[i] == element)
            return i;

    return size;
}

bool _isUnique(long long *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        const size_t pos = _find(arr, size, (int) arr[i]);
        if (pos != i && pos != size)
            return 0;
    }

    return 1;
}

long long _getSum(int *a, size_t n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

float _getDistance(int *a, size_t n) {
    float distance = 0;
    for (size_t i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

int _cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    return arg1 > arg2;
}

int _countNUnique(long long *a, size_t n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), _cmp_long_long);

    int counterOfUnique = 1;
    size_t i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }

    return counterOfUnique;
}

bool _isNonDescendingSorted(int *a, size_t n) {
    for (size_t i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return 0;
    return 1;
}

int _countValues(const int *a, size_t n, size_t value) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] == value)
            count++;

    return count;
}