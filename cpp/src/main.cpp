#include "heap.hpp"
#include "quicksort.hpp"
#include "insertionsort.hpp"

int main() {
  const int BIG_DATA_SIZE = 10000000;
  auto arr = std::vector<int>();
  for (int i = 0; i < BIG_DATA_SIZE; ++i) {
    arr.push_back(random() % 10);
    //      arr.push_back(random());
  }
  auto arr2 = arr;
  clock_t begin = clock();
  heap_sort(arr);
  clock_t end = clock();
  std::cout << "total time for heap sort: "
            << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

  begin = clock();
  quicksort2ways(arr2, 0, arr.size());
  end = clock();
  std::cout << "total time for quick sort: "
            << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;

  //  auto arr = vector{5, 4, 3, 2, 1};
  //  insertion_sort(arr, 0, arr.size());
  //  for (auto i : arr)
  //    std::cout << i << std::endl;

  return 0;
}
