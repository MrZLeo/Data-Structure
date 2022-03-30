project(src)

include_directories(./)

add_executable(src
    quicksort.hpp
    heap.hpp
    main.cpp
    insertionsort.hpp
    countsort.hpp
    radixsort.hpp
    matrix_chain.hpp
    matrix_chain.cpp
    lcs.h
    shortest_path.h
    lcsubstring.h)
