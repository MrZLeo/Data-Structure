#include "heap.hpp"

int main() {
  const int BIG_DATA_SIZE = 100000000;
  auto arr = std::vector<int>();
  for (auto i = BIG_DATA_SIZE; i > 0; --i) {
    arr.push_back(i);
  }
  clock_t begin = clock();
  heap_sort(arr);
  clock_t end = clock();
  std::cout << "total time: " << double(end - begin) / CLOCKS_PER_SEC
            << std::endl;

  return 0;
}
