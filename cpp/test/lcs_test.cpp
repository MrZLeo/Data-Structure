#include "lcs.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

TEST(lcs, case1) {
    std::string a = "xzyzzyx";
    std::string b = "zxyyzxz";

    int res = algo::lcs(a, b);
    std::cout << "res = " << res << std::endl;
    EXPECT_EQ(res, 4); // ans from LeetCode
}

TEST(lcs, case2) {
    std::string a = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
    std::string b = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";

    int res = algo::lcs(a, b);
    std::cout << "res = " << res << std::endl;
    EXPECT_EQ(res, 56); // ans from LeetCode
}

