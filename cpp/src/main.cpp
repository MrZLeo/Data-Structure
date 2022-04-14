#include "graph.h"
#include <cstdint>
#include <iostream>
#include <ostream>

int main()
{
    using std::cout;
    using std::endl;

    auto t = WeightedGraph("g.txt");
    auto res = t.bellman_ford(0);
    auto res2 = t.floyd();

    for (auto iter : res2) {
        for (auto i : iter) {
            if (i == INT32_MAX)
                cout << "∞"
                     << "\t";
            else
                cout << i << "\t";
        }
        cout << "\n";
    }
}
