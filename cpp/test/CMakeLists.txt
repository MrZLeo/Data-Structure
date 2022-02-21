project(test)

add_subdirectory(lib/gtest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run heap_test.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)