#include "matrix_chain.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>

TEST(matrix_chain, case1)
{
    auto v = std::vector { 3, 5, 2, 1, 10 };

    int res = matrix_chain(v);
    std::cout << "res = " << res << "\n";
}

TEST(matrix_chain, case2)
{
    auto v = std::vector { 2, 7, 3, 6, 10 };

    int res = matrix_chain(v);
    std::cout << "res = " << res << "\n";
}

TEST(matrix_chain, case3)
{
    auto v = std::vector { 10, 3, 15, 12, 7, 2 };

    int res = matrix_chain(v);
    std::cout << "res = " << res << "\n";
}

TEST(matrix_chain, case4)
{
    auto v = std::vector { 7, 2, 4, 15, 20, 5 };

    int res = matrix_chain(v);
    std::cout << "res = " << res << "\n";
}
