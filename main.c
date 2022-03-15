/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "libs/algorithms/base/base.h"
#include "libs/govnocode/DiscMath/lr_1.1/lr_1.1.h"


#define TIME_TEST(testCode, time) {             \
    clock_t start_time = clock();               \
    testCode                                    \
        clock_t end_time = clock();             \
    clock_t sort_time = end_time - start_time;  \
    time = (double) sort_time / CLOCKS_PER_SEC; \
}

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

#define DECREASE_FACTOR 1.24733

#define SEAD 10000


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



///////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

void generateRandomArray(int *a, size_t n) {
    srand(time(NULL));
    for (size_t i = 0; i < n; i++) {
        a[i] = rand() % SEAD;
        printf("%d ", a[i]);
    }
    printf("\n");
}

void generateOrderedArray(int *a, size_t n) {
    srand(time(NULL));
    a[0] = rand() % SEAD;
    for (size_t i = 1; i < n; i++) {
        a[i] = rand() % SEAD + 1;
        srand(a[i]);
        printf("%d ", a[i]);
    }
}

///////////////////////////////////////////////////////////////////////////
*/
/*
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
                checkTime(sorts[i].name, generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }

    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time: %.3f s.\n", time);

        char filename[256];
        sprintf(filename, "./data%s.csv", name);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        outputArray_(innerBuffer, size);

        exit(1);
    }
}*//*


int main() {
    int a[100];
    generateRandomArray(a, 100);
    generateOrderedArray(a, 100);


    return 0;
}
*/

#include "libs/tasks/5cTasks/5cTasks.h"

int main() {
    timeExperiment();

    return 0;
}