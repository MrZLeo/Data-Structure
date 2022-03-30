#ifndef __LCSUBSTRING_H__
#define __LCSUBSTRING_H__

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace algo {

int lcss(std::string& a, std::string& b)
{

    using std::string;
    using std::vector;

    const int n = a.size();
    const int m = b.size();

    vector<vector<int>> memo = vector(n + 1, vector(m + 1, 0));

    int maxVal = 0;
    int x = 0;
    int y = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
                if (memo[i][j] > maxVal) {
                    maxVal = memo[i][j];
                    x = i;
                    y = j;
                }
            } else {
                memo[i][j] = 0;
            }
        }
    }

    std::stack<char> res;
    for (int i = x, j = y; i > 0 && j > 0; --i, --j) {
        if (memo[i][j] != 0) {
            res.push(a[i - 1]);
        }
    }

    std::cout << "longest substring: ";
    while (!res.empty()) {
        char c = res.top();
        res.pop();
        std::cout << c;
    }

    std::cout << std::endl;

    return maxVal;
}

} // namespace algo
#endif //__LCSUBSTRING_H__
