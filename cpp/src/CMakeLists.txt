project(src)

include_directories(./)

add_executable(src
        quicksort.hpp heap.hpp main.cpp insertionsort.hpp countsort.hpp radixsort.hpp
        )

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build)
