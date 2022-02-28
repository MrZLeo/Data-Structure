#ifndef DATA_STRUCTURE_ALGORITHM_SRC_RADIXSORT_HPP
#define DATA_STRUCTURE_ALGORITHM_SRC_RADIXSORT_HPP

#include <vector>
#include "countsort.hpp"

using std::vector;

template<class T>
static inline T mask_value(T value, int mask) {
    return (value & (1 << mask)) >> mask;
}

template<class T>
void count_sort_with_mask(vector<T> &arr, int mask) {
    auto temp = vector(2, 0);
    for (int i = 0; i < arr.size(); ++i) {
        temp[mask_value(arr[i], mask)]++;
    }

    temp[1] += temp[0];

    vector<T> res = vector(arr.size(), 0);
    for (int i = arr.size() - 1; i >= 0; --i) {
        auto v = mask_value(arr[i], mask);
        res[temp[v] - 1] = arr[i];
        temp[v]--;
    }
    arr = res;
}

template<class T>
void radix_sort(vector<T> &arr) {
    for (int i = 0; i < 8 * sizeof(T); ++i) {
        count_sort_with_mask<T>(arr, i);
    }
}
#endif //DATA_STRUCTURE_ALGORITHM_SRC_RADIXSORT_HPP
