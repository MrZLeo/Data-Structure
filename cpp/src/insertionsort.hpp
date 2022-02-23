#ifndef DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP
#define DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP

#include <vector>

using std::vector;

template <class T> void insertion_sort(vector<T> &arr, int l, int r) {
  for (int i = l + 1; i < r; ++i) {
    int j = i;
    while (j >= l && arr[i] < arr[j])
      j--;
    std::swap(arr[j], arr[i]);
  }
}

#endif // DATA_STRUCTURE_ALGORITHM_SRC_INSERTIONSORT_HPP
