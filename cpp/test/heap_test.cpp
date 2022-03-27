#include "heap.hpp"
#include "gtest/gtest.h"
#include <vector>
using namespace algo;

TEST(reverse, t1) {
    auto arr = std::vector<int>({4, 3, 2, 1, 0});
    heap_sort(arr);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(i, arr[i]);
    }
}

TEST(random, normalCase) {
    auto arr = std::vector<int>(
        {21, 1234, 24356, 7645, 123, 1354, 7467, 86, 123, 245, 345});
    heap_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(random, bigDataSet) {
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        arr.push_back(random());
    }
    heap_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(lotsSameNum, bigDataSet) {
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        arr.push_back(random() % 100);
    }
    heap_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(sorted, t1) {
    auto arr = std::vector({1, 2, 3, 4, 5, 6});
    heap_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(lotsSameNum, t1) {
    auto arr = std::vector{1, 1, 2, 3, 4, 5, 4, 1, 3, 2, 1, 1, 0, 1, 1, 1};
    heap_sort(arr);
    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(reverse, bigDataSet) {
    const int BIG_DATA_SIZE = 100000000;
    auto arr = std::vector<int>();
    for (auto i = BIG_DATA_SIZE; i > 0; --i) {
        arr.push_back(i);
    }
    heap_sort(arr);

    for (int i = 1; i < arr.size(); ++i) {
        EXPECT_GE(arr[i], arr[i - 1]);
    }
}

TEST(heap, priority_queue) {
    Heap<int> heap;

    for (int i = 100; i >=0 ; --i)
        heap.push(i);

    for (int i = 1; i < heap.size(); ++i) {
        int t1 = heap.pop();
        int t2 = heap.top();
        EXPECT_GE(t1, t2);
    }

    Heap<double> heap2;

    for (int i = 1; i < heap2.size(); --i)
        heap2.push(random() % 100 + 0.1);

    for (int i = 1; i < heap2.size(); ++i) {
        int t1 = heap2.pop();
        int t2 = heap2.top();
        EXPECT_GE(t1, t2);
    }
}