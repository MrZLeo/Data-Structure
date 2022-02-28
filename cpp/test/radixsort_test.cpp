#include "radixsort.hpp"
#include "gtest/gtest.h"
#include <vector>

TEST(radixsort, random) {
    auto arr = std::vector<int>(
        {21, 1234, 24356, 7645, 123, 1354, 7467, 86, 123, 245, 345});
    radix_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

