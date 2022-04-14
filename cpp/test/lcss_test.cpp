#include "gtest/gtest.h"
#include "lcsubstring.h"
#include <iostream>
#include <string>

TEST(lcss, case1)
{
    std::string a = "xzyzzyx";
    std::string b = "zxyyzxz";

    int res = algo::lcss(a, b);
    std::cout << "res = " << res << std::endl;
}

TEST(lcss, case2)
{
    std::string a = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCALLAAQANKESSSESFISRLLAIVAD";
    std::string b = "MAEEEVAKLEKHLMLLRQEYVKLQKKLAETEKRCTLLAAQANKENSNESFISRLLAIVAG";

    int res = algo::lcss(a, b);
    std::cout << "res = " << res << std::endl;
}
