#include "shortest_path.hpp"
#include <gtest/gtest.h>

TEST(shortest_path, case1)
{
    using std::cout;
    using std::endl;

    auto t = Graph("/Users/mrzleo/CLionProjects/Data-Structure-Algorithm/cpp/g.txt");
    auto res = t.shortest_path();
}
