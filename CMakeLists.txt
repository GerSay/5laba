cmake_minimum_required(VERSION 3.20)
project(workProject C)

set(CMAKE_C_STANDARD 11)

add_executable(workProject main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/random/random.c
        libs/algorithms/random/random.h libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/unordered_array_set/unordered_array_set.h libs/data_structures/ordered_array_set/ordered_array_set.c
        libs/data_structures/ordered_array_set/ordered_array_set.h libs/data_structures/tests/unordered_array_set_test/unordered_array_set_test.c
        libs/data_structures/tests/unordered_array_set_test/unordered_array_set_test.h libs/data_structures/tests/ordered_array_set_tests/ordered_array_set_tests.c
        libs/data_structures/tests/ordered_array_set_tests/ordered_array_set_tests.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h
        libs/algorithms/base/base.c libs/algorithms/base/base.h libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h
        libs/data_structures/tests/vector_tests/vector_tests.c libs/data_structures/tests/vector_tests/vector_tests.h
        libs/govnocode/DiscMath/DiscMath.c libs/govnocode/DiscMath/DiscMath.h libs/data_structures/vectorVoid/vectorVoid.c
        libs/data_structures/vectorVoid/vectorVoid.h libs/data_structures/tests/vectorVoid_tests/vectorVoid_tests.c
        libs/data_structures/tests/vectorVoid_tests/vectorVoid_tests.h "libs/tasks/5dTasks/5dTasks.c" "libs/tasks/5dTasks/5dTasks.h"
        libs/data_structures/tests/5dTasks_tests/5dTasks_tests.c libs/data_structures/tests/5dTasks_tests/5dTasks_tests.h
        libs/data_structures/tests/matrix_tests/matrix_tests.c libs/data_structures/tests/matrix_tests/matrix_tests.h
        libs/govnocode/whoAreKB/whoAreKB.c libs/govnocode/whoAreKB/whoAreKB.h libs/data_structures/string_/string_.c
        libs/data_structures/string_/string_.h libs/tasks/5eTasks/5eTasks.c libs/tasks/5eTasks/5eTasks.h libs/govnocode/DiscMath/lr_1.1/lr_1.1.c
        libs/govnocode/DiscMath/lr_1.1/lr_1.1.h libs/tasks/5cTasks/5cTasks.c libs/tasks/5cTasks/5cTasks.h)

add_library(str libs/data_structures/string_/string_.h libs/data_structures/string_/string_.c
        libs/data_structures/tests/5eTasks_tests/5eTasks_tests.c libs/data_structures/tests/5eTasks_tests/5eTasks_tests.h
        libs/govnocode/DiscMath/lr_1.1/lr_1.1.c libs/govnocode/DiscMath/lr_1.1/lr_1.1.h libs/tasks/5cTasks/5cTasks.c libs/tasks/5cTasks/5cTasks.h)

target_link_libraries(str)