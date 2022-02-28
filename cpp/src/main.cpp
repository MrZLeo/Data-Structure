#include "heap.hpp"
#include "quicksort.hpp"
#include "insertionsort.hpp"
#include "countsort.hpp"
#include "radixsort.hpp"

int main() {

    using std::cout;
    using std::endl;

//    const int BIG_DATA_SIZE = 10000000;
//    auto arr = std::vector<int>();
//    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
//        arr.push_back(random() % 10);
//        //      arr.push_back(random());
//    }
//    auto arr2 = arr;
//    clock_t begin = clock();
//    heap_sort(arr);
//    clock_t end = clock();
//    std::cout << "total time for heap sort: "
//              << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
//
//    begin = clock();
//    quicksort2ways(arr2, 0, arr.size());
//    end = clock();
//    std::cout << "total time for quick sort: "
//              << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

    //  auto arr = vector{5, 4, 3, 2, 1};
    //  insertion_sort(arr, 0, arr.size());
    //  for (auto i : arr)
    //    std::cout << i << std::endl;

//    auto arr3 = std::vector{4, 3, 2, 1, 1};
//    count_sort<int, 5>(arr3);
//    for (auto v : arr3) {
//        std::cout << v << std::endl;
//    }

    auto arr = vector{8, 4, 2, 1, 1, 2, 3, 4, 5, 6, 7};
    radix_sort(arr);
    for (auto v : arr) {
        cout << v << endl;
    }
    return 0;
}
