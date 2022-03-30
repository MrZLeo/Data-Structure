#include "quicksort.hpp"
#include "gtest/gtest.h"
#include <vector>

TEST(quicksort, reverse)
{
    auto arr = std::vector<int>({ 4, 3, 2, 1, 0 });
    quicksort(arr, 0, arr.size());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, arr[i]);
    }
}

TEST(quicksort, randomNormalCase)
{
    auto arr = std::vector<int>(
        { 21, 1234, 24356, 7645, 123, 1354, 7467, 86, 123, 245, 345 });
    quicksort(arr, 0, arr.size());
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(quicksort, randomBigDataSet)
{
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        arr.push_back(random());
    }
    quicksort(arr, 0, arr.size());
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(quicksort, lotsSameNumBigDataSet)
{
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        arr.push_back(random() % 100);
    }
    quicksort2ways(arr, 0, arr.size());
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(quicksort, sorted)
{
    auto arr = std::vector({ 1, 2, 3, 4, 5, 6 });
    quicksort(arr, 0, arr.size());
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(quicksort, lotsSameNum)
{
    auto arr = std::vector { 1, 1, 2, 3, 4, 5, 4, 1, 3, 2, 1, 1, 0, 1, 1, 1 };
    quicksort2ways(arr, 0, arr.size());
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(quicksort, reverseBigDataSet)
{
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (auto i = BIG_DATA_SIZE; i > 0; --i) {
        arr.push_back(i);
    }
    quicksort(arr, 0, arr.size());

    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(insertionsort, reverse)
{
    auto arr = std::vector<int>({ 4, 3, 2, 1, 0 });
    insertion_sort(arr, 0, arr.size());
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, arr[i]);
    }
}