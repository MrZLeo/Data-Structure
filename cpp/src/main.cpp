#include "graph.hpp"
#include "knapsack.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>
#include <queen.hpp>
#include <vector>

int main()
{
    using std::cout;
    using std::endl;

    std::vector<int> v { 65, 20, 30, 60, 40 };
    std::vector<int> w { 30, 10, 20, 50, 40 };

    int res = find_kth(v, 0, v.size(), 1);
    cout << res << endl;
    res = find_kth(v, 0, v.size(), 2);
    cout << res << endl;
    res = find_kth(v, 0, v.size(), 3);
    cout << res << endl;
    res = find_kth(v, 0, v.size(), 4);
    cout << res << endl;
    res = find_kth(v, 0, v.size(), 5);
    cout << res << endl;
    /* queen(8); */
}
