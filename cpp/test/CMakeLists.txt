project(test)

add_subdirectory(lib/gtest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)

add_executable(Google_Tests_run main.cpp
        heap_test.cpp quicksort_test.cpp countsort_test.cpp radixsort_test.cpp test_helper.hpp)

target_link_libraries(Google_Tests_run gtest gtest_main)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build)
