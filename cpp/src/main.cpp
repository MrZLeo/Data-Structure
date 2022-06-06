#include "graph.h"
#include "knapsack.h"
#include "mergesort.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>
#include <queen.h>
#include <vector>

int main()
{
    using std::cout;
    using std::endl;

    std::vector<int> v { 65, 20, 30, 60, 40 };
    std::vector<int> w { 30, 10, 20, 50, 40 };

    algo::merge_sort<int>(v);
    for (const auto &iter : v) {
        cout << iter << " ";
    }

    cout << endl;

    algo::merge_sort<int>(w);
    for (const auto &iter : w) {
        cout << iter << " ";
    }
    cout << std::endl;
    /* queen(8); */
}
