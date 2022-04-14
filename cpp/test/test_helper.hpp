#ifndef DATA_STRUCTURE_ALGORITHM_TEST_TEST_HELPER_HPP
#define DATA_STRUCTURE_ALGORITHM_TEST_TEST_HELPER_HPP

#include <ctime>
#include <vector>

typedef void (*sort_func)(std::vector<int> &);

template<typename F = sort_func>
double sort_speed(int size, F f)
{

    using std::vector;
    auto arr = vector<int>();
    for (int i = 0; i < size; ++i) {
        arr.push_back(random());
    }

    auto begin = clock();
    f(arr);
    auto end = clock();
    return double(end - begin) / CLOCKS_PER_SEC;
}

#endif // DATA_STRUCTURE_ALGORITHM_TEST_TEST_HELPER_HPP
