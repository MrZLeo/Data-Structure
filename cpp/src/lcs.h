#ifndef __LCS_H__
#define __LCS_H__

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace algo {

int lcs(std::string& a, std::string& b)
{

    using std::string;
    using std::vector;

    const int n = a.size();
    const int m = b.size();

    vector<vector<int>> memo = vector(n + 1, vector(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    std::stack<char> res;
    for (int i = n, j = m; i > 0 && j > 0;) {
        if (memo[i][j] == memo[i - 1][j - 1] + 1) {
            res.push(a[i - 1]);
            i--;
            j--;
        } else {
            if (memo[i][j] == memo[i - 1][j]) {
                i--;
            } else {
                j--;
            }
        }
    }

    std::cout << "longest subsequence: ";
    while (!res.empty()) {
        char c = res.top();
        res.pop();
        std::cout << c;
    }

    std::cout << std::endl;

    return memo[n][m];
}

} // namespace algo

#endif
