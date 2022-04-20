#include "graph.h"
#include "knapsack.h"
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
    auto res = algo::knapsack_01_backtracking(v, w, 100);
    for (const auto &iter : res) {
        cout << iter << " ";
    }
    cout << std::endl;
    /* queen(8); */
}
