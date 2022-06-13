#include <cassert>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s)
    {
        const int n = s.size();
        // memo[i][j] = str[i..j] is a palindromic substring
        vector<vector<bool>> memo = vector(n + 1, vector(n + 1, false));

        // res is the size of palindromic substring
        int res = n;

        // any one char can be a palindromic substring
        for (int i = 1; i <= n; ++i)
            memo[i][i] = true;

        // we need to calculate by step
        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i <= n - l + 1; ++i) {
                int j = i + l - 1;

                // j - i == 1 will means situation like memo[1][2], which will
                // lead to i + 1 > j - 1, but in this situation, we just need
                // to judge whether s[i-1] == s[j-1]
                if ((j - i <= 1 || memo[i + 1][j - 1] == true)
                    && s[i - 1] == s[j - 1]) {
                    memo[i][j] = true;
                    res++;
                }
            }
        }

        return res;
    }
};

void test()
{
    vector<pair<string, int>> test = {
        { "abc", 3 },
        { "aaa", 6 },
        { "aba", 4 },
        { "ababa", 9 },
        { "bcbasd", 7 },
        { "abcdcbartjknbf", 17 },
        { "longtimenosee", 14 },
    };

    for (auto t : test) {
        assert(Solution().countSubstrings(t.first) == t.second);
    }
}
