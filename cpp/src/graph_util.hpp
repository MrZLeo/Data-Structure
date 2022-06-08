#ifndef __GRAPH_UTIL_H__
#define __GRAPH_UTIL_H__

#include <iostream>
#include <vector>

namespace graph_util {

inline void print_path(std::vector<int> pre, int s, int t)
{
    if (t == s)
        return;

    int cur = t;
    std::cout << s << "->" << t << ": ";
    std::vector<int> res;
    while (cur != s) {
        res.push_back(cur);
        cur = pre[cur];
    }
    res.push_back(s);
    std::reverse(res.begin(), res.end());

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i != res.size() - 1)
            std::cout << " -> ";
    }
    std::cout << std::endl;
}

}

#endif //__GRAPH_UTIL_H__
