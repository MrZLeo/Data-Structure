#ifndef __MAX_SUM__
#define __MAX_SUM__

#include <algorithm>
#include <cstdint>
#include <vector>

inline int max_sum(std::vector<int> &a)
{
    using std::vector;
    const int n = a.size();

    // memo[i]: max sum end of i, i.e. a[?..i]
    // memo[i] is just related to memo[i - 1] and a[i]
    // if a[i] + memo[i - 1] < a[i], then a[i..i] is the best choice
    // else memo[i - 1] + a[i] is the best choice
    std::vector<int> memo = vector(n, 0);

    // if a[0] is positive, max sum of a[0..0] is a[0]
    // else is NULL
    memo[0] = a[0] > 0 ? a[0] : 0;

    int maxVal = memo[0];
    for (int i = 1; i < n; ++i) {
        memo[i] = std::max(memo[i - 1] + a[i], a[i]);
        maxVal = std::max(memo[i], maxVal);
    }

    return maxVal;
}

inline int max_sum2(std::vector<int> &a)
{
    using std::vector;
    int pre = 0;
    int res = INT32_MIN;

    for (const auto &num : a) {
        pre = std::max(pre + num, num);
        res = std::max(pre, res);
    }

    return res;
}

inline int max_sum3(std::vector<int> &a)
{
    int sum = 0;
    int t = 0;
    int l, r;
    int rl, rr;
    for (int i = 0; i < a.size(); ++i) {
        if (t > 0) {
            t += a[i];
            r = i;
        } else {
            t = a[i];
            l = i;
            r = i;
        }
        if (t > sum) {
            sum = t;
            rl = l;
            rr = r;
        }
    }

    return sum;
}

#endif // __MAX_SUM__
