#ifndef __MERGESORT_HPP__
#define __MERGESORT_HPP__

#include <vector>

namespace algo {

template<class T>
void __merge(std::vector<T> &arr, int l, int mid, int r)
{
    int p = l;
    int q = mid + 1;
    std::vector<T> res(r - l + 1);

    int idx = 0;
    while (p <= mid && q <= r) {
        if (arr[p] < arr[q])
            res[idx++] = arr[p++];
        else
            res[idx++] = arr[q++];
    }

    while (p <= mid)
        res[idx++] = arr[p++];
    while (q <= r)
        res[idx++] = arr[q++];

    idx = 0;
    for (int i = l; i <= r; ++i)
        arr[i] = res[idx++];
}

/**
 * sort array of range [l, r]
 */
template<class T>
void __merge_sort(std::vector<T> &arr, int l, int r)
{
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;
    __merge_sort(arr, l, mid);
    __merge_sort(arr, mid + 1, r);
    __merge(arr, l, mid, r);
}

template<class T>
void merge_sort(std::vector<T> &arr)
{
    __merge_sort(arr, 0, arr.size() - 1);
}

}

#endif
