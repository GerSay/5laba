#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/*
#define typeArr (a) \
if (a == 1)
return char;
if (a == 2)
    return short int;
if (a == 4)
    return int;
*/



#define TIME_TEST/*({  \
sortFunc(innerBuffer, size); \
}, time);            \*/

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])


typedef struct sortFunc {
    void (*sort) (int *a, size_t n);
    char name[64];
} sortFunc;

typedef struct generatingFunc {
    void (*generate) (int *a, size_t n);
    char name[64];
} generatingFunc;

double getTime() {
    clock_t start_time = clock();
    //code
    clock_t end_time = clock();
    clock_t sort_time = end_time - start_time;

    return (double) sort_time / CLOCKS_PER_SEC;
}

void checkTime(void (*sortFunc) (int *, size_t),
               void (*generateFunc) (int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    //генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    //замер времени
    double time;
    TIME_TEST({
                  sortFunc(innerBuffer, size);
              }, time);
}

void selectionSort(typeArr *a, size_t n) {

}

void timeExperiment() {
    //описание функций сортировки
    sortFunc sorts[] = {
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            //Остальные сортировки
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    //Описание функций генерации
    generatingFunc generatingFuncs[] = {
            //генерируется случайный массив
            {generateRandomArray, "random"},
            //генерируется массив 0, 1, 2, ..., n - 1
            {generateOrderedArray, "ordered"},
            //генерируется массив n - 1, n - 2, ..., 0
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    //запись статистики в файл
    for (size_t size = 10000; size <= 10000; size += 10000) {
        printf("------------------------------\n");
        printf("Size: %d\n", size);
        for (size_t i = 0; i < FUNCS_N; i++) {
            for (size_t j = 0; j < CASES_N; j++) {
                //генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].name, generatingSuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperinment();

    return 0;
}