#include "gtest/gtest.h"
#include "max_sum.h"
#include <iostream>
#include <vector>

TEST(max_sum, case1)
{
    auto v = std::vector { -2, 11, -4, 13, -5, -2 };

    int res = max_sum(v);
    int res2 = max_sum2(v);

    std::cout << "res1 = " << res << std::endl;
    std::cout << "res2 = " << res2 << std::endl;
}
