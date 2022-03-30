#include "countsort.hpp"
#include "gtest/gtest.h"
#include <vector>

TEST(countsort, normal)
{
    auto arr = std::vector { 5, 4, 3, 2, 1, 1, 1, 1 };
    count_sort<int, 6>(arr);
    for (int i = 1; i < arr.size(); ++i) {
        ASSERT_GE(arr[i], arr[i - 1]);
    }
}