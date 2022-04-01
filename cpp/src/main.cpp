#include "heap.hpp"
#include "lcsubstring.h"
#include "shortest_path.h"
#include <iostream>
#include <ostream>

int main()
{
    using std::cout;
    using std::endl;

    auto t = Graph("g.txt");
    auto res = t.shortest_path();
    cout << "res = " << res << endl;

    /* std::string a = "xzyzzyx"; */
    /* std::string b = "zxyyzxz"; */

    /* int res = algo::lcss(a, b); */
    /* std::cout << "res = " << res << std::endl; */
}
