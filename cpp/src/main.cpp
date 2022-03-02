#include "countsort.hpp"
#include "heap.hpp"
#include "insertionsort.hpp"
#include "quicksort.hpp"
#include "radixsort.hpp"

int main() {

    using std::cout;
    using std::endl;

    const int BIG_DATA_SIZE = 1000000;
    auto arr = std::vector<int>();
    for (int i = 0; i < BIG_DATA_SIZE; ++i) {
        arr.push_back(random() % 10);
        //      arr.push_back(random());
    }
    auto arr2 = arr;

    clock_t begin = clock();
    radix_sort(arr);
    clock_t end = clock();
    std::cout << "total time for radix sort: "
              << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

    begin = clock();
    quicksort2ways(arr2, 0, arr.size());
    end = clock();
    std::cout << "total time for quick sort: "
              << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

    return 0;
}
