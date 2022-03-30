#ifndef __MAX_SUM__
#define __MAX_SUM__

#include <algorithm>
#include <cstdint>
#include <vector>
int max_sum(std::vector<int>& a)
{

    using std::vector;
    const int n = a.size();

    std::vector<int> memo = vector(n, 0);
    memo[0] = a[0] > 0 ? a[0] : 0;

    for (int i = 1; i < n; ++i) {
        memo[i] = std::max(memo[i - 1] + a[i], a[i]);
    }

    int maxVal = INT32_MIN;
    for (int i = 0; i < n; ++i)
        maxVal = std::max(memo[i], maxVal);

    return maxVal;
}

int max_sum2(std::vector<int>& a)
{
    using std::vector;
    int pre = 0;
    int res = INT32_MIN;

    for (const auto& num : a) {
        pre = std::max(pre + num, num);
        res = std::max(pre, res);
    }

    return res;
}

#endif // __MAX_SUM__
