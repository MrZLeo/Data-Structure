#include "shortest_path.h"
#include <gtest/gtest.h>

TEST(shortest_path, case1)
{
    using std::cout;
    using std::endl;

    auto t = Graph("/Users/mrzleo/CLionProjects/Data-Structure-Algorithm/cpp/g.txt");
    auto res = t.shortest_path(0);
    for (int i = 0; i < res.size(); ++i) {
        cout << i << ": " << res[i] << endl;
    }
}
