#ifndef DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP
#define DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP

#include <vector>

using std::vector;

template <class T>
void insertion_sort(vector<T>& arr, int l, int r)
{
    for (int i = l + 1; i < r; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; --j)
            arr[j] = arr[j - 1];
        std::swap(arr[j], e);
    }
}

#endif // DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP
