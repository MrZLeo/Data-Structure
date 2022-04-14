#include "gtest/gtest.h"
#include "iostream"
#include "radixsort.hpp"
#include "test_helper.hpp"
#include <vector>

using namespace std;

TEST(radixsort, random)
{
    auto arr = std::vector<int>(
        { 21, 1234, 24356, 7645, 123, 1354, 7467, 86, 123, 245, 345 });
    radix_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(radix_sort, speed_test)
{
    auto time = sort_speed(10000000, radix_sort);
    cout << "sort time: " << time << "s" << endl;
}
