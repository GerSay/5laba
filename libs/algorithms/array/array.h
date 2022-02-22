#ifndef WORKPROJECT_ARRAY_H
#define WORKPROJECT_ARRAY_H

# include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, size_t n, int x);

void copyArray(int *a, const int *b, size_t size);

int compare_ints(void *a, void *b);

int binarySearchLess(int *a, int size, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t binarySearch_(const int *a, size_t n, int x);

size_t binarySearchIf_(const int *a, const size_t n, int x, int (*f) (int, int));

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

void inputArrayD_(int *m, size_t size);

int _getMax(int *a, size_t n);

int _getMin(int *a, size_t n);

size_t _find(long long *arr, size_t size, int element);

bool _isUnique(long long *arr, size_t size);

long long _getSum(int *a, size_t n);

float _getDistance(int *a, size_t n);

int _cmp_long_long(const void *pa, const void *pb);

int _countNUnique(long long *a, size_t n);

bool _isNonDescendingSorted(int *a, size_t n);

int _countValues(const int *a, size_t n, size_t value);




#endif //WORKPROJECT_ARRAY_H
