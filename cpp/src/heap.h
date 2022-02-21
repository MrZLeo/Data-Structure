#include <vector>
#include <iostream>

using std::vector;

template<class E>
class Heap {
private:
  vector<E> &arr;
  int _size;

public:
  Heap(vector<E> &arr) : arr(arr), _size(arr.size()) {
	for (int i = arr.size() / 2 - 1; i != -1; --i) {
	  heapify(i);
	}
  }

  int size();

  void heapify(int index);

  void swap(int i, int j);

  int *size_mut();
};

template<class E>
int Heap<E>::size() { return _size; }

template<class E>
void Heap<E>::heapify(int index) {
  while (true) {
	auto max = index;
	auto l = index * 2 + 1;
	auto r = index * 2 + 2;
	if (l < _size)
	  max = l;
	if (r < _size && arr[r] > arr[max])
	  max = r;

	// last one, recursion end
	if (index == max)
	  break;

	if (arr[max] > arr[index])
	  std::swap(arr[index], arr[max]);
	index = max;
  }
}

template<class E>
void Heap<E>::swap(int i, int j) {
  std::swap(arr[i], arr[j]);
}

template<class E>
int *Heap<E>::size_mut() {
  return &_size;
}

template<class T>
void heap_sort(vector<T> &arr) {
  auto heap = Heap(arr);
  auto size = heap.size() - 1;
  for (auto i = size; i != 0; --i) {
	heap.swap(0, i);
	(*heap.size_mut())--;
	heap.heapify(0);
  }
}