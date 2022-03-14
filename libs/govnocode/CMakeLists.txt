add_library(govnocode
        DiscMath/DiscMath.c
        DiscMath/lr_1.1/lr_1.1.c
        whoAreKB/whoAreKB.c
)

target_link_libraries(data_structures algorithms tasks govnocode)