#include <iostream>
#include <type_traits>
#include <vector>

using std::vector;

template<class E>
class Heap {
private:
    vector<E> arr;
    int _size;

public:
    Heap(vector<E> &arr)
        : arr(arr)
        , _size(arr.size())
    {
        for (int i = arr.size() / 2 - 1; i != -1; --i) {
            heapify(i);
        }
    }

    Heap()
        : arr(vector<E>(10, 0))
        , _size(0)
    {
    }

    Heap(size_t capacity)
        : arr(vector<E>(capacity, 0))
        , _size(0)
    {
    }

    int size();
    void heapify(int index);
    E top();
    void push(E e);
    E pop();
};

template<class E>
int Heap<E>::size() { return _size; }

template<class E>
void Heap<E>::heapify(int index)
{
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
E Heap<E>::top() { return arr[0]; }

template<class E>
void Heap<E>::push(E e)
{
    // check whether it is full
    if (_size == arr.size())
        arr.push_back(e); // vector's auto resize
    else
        arr[_size] = e;

    int idx = _size;

    while (idx > 0 && arr[(idx - 1) / 2] < arr[idx]) {
        std::swap(arr[idx], arr[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }

    _size++;
}

template<class E>
E Heap<E>::pop()
{
    E ret = arr[0];
    std::swap(arr[0], arr[_size - 1]);
    _size--;
    heapify(0);
    return ret;
}

// algorithm
namespace algo {

template<class T>
void heap_sort(vector<T> &arr)
{
    Heap<T> heap = Heap(arr);
    for (int i = arr.size() - 1; i >= 0; --i) {
        arr[i] = heap.pop();
    }
}

} // namespace algo
