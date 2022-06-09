#ifndef __LCS_H__
#define __LCS_H__

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

namespace algo {

inline int lcs(std::string &a, std::string &b)
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

// 最长回文子序列
inline int lcp(std::string &str)
{
    using std::cout;
    using std::endl;
    using std::vector;

    const int n = str.size();

    // memo[i][j]: the longest str[i..j] can have
    vector<vector<int>> memo = vector(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
        memo[i][i] = 1;

    // we have compute it from |j - i| == 1 and > 1...
    // l: the len of str[i..j]
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            if (str[i - 1] == str[j - 1]) {
                memo[i][j] = memo[i + 1][j - 1] + 2;
            } else {
                memo[i][j] = std::max(memo[i + 1][j], memo[i][j - 1]);
            }
        }
    }

    // reconstruction
    vector<char> v;
    int l = 1;
    int r = n;
    int length = memo[1][n];
    while (length > 0 && l <= n && r > 0) {
        if (str[l - 1] == str[r - 1]) {
            v.push_back(str[l - 1]);
            l++;
            r--;
            length -= (l == r ? 1 : 2);
        } else {
            if (memo[l + 1][r] > memo[l][r - 1])
                l++;
            else
                r--;
        }
    }

    // copy another half
    // if len is odd, we have one char in the middle
    const int len = (memo[1][n] & 0x1) == 0 ? v.size() : v.size() - 1;

    for (int i = len - 1; i >= 0; --i)
        v.push_back(v[i]);

    for (auto iter : v) {
        cout << iter;
    }
    cout << endl;

    // memo[1][n] is str[1..n] which index start with 1
    // this is the answer we want
    return memo[1][n];
}

} // namespace algo

#endif
