add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c
        ordered_array_set/ordered_array_set.c
        tests/ordered_array_set_tests/ordered_array_set_tests.c
        matrix/matrix.c
        vector/vector.c
        tests/vector_tests/vector_tests.c
        vectorVoid/vectorVoid.c
        tests/vectorVoid_tests/vectorVoid_tests.c
        matrix/matrix.c
        string_/string_.c
        )

        #define

target_link_libraries(data_structures algorithms tasks)
