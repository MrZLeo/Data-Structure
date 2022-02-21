#include "heap.h"

int main() {
  auto t = vector({4, 3, 2, 1});
  heap_sort(t);
  for (auto i : t)
	std::cout << i << std::endl;

  return 0;
}
