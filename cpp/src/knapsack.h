#ifndef __KNAPSACK_H__
#define __KNAPSACK_H__

#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

namespace algo {

struct k_cmp {
    bool operator()(const std::tuple<int, int, double>& a,
        const std::tuple<int, int, double>& b) const
    {
        double a1 = std::get<2>(a);
        double b1 = std::get<2>(b);

        return a1 > b1;
    }
};

int knapsack_frac(std::vector<int> v, std::vector<int> w, int limit)
{
    assert(v.size() == w.size());
    const int n = v.size();

    std::vector<std::tuple<int, int, double>> v_w(n);
    for (int i = 0; i < n; ++i) {
        v_w[i] = std::make_tuple(v[i], w[i], (double)v[i] / w[i]);
    }

    std::sort(v_w.begin(), v_w.end(), k_cmp());

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int weigh = std::get<1>(v_w[i]);
        int value = std::get<0>(v_w[i]);
        if (weigh <= limit) {
            res += value;
            limit -= weigh;
        } else {
            double frac = 1.0 * limit / weigh;
            res += value * frac;
            break;
        }
    }

    return res;
}

int knapsack_01(std::vector<int> v, std::vector<int> w, int limit)
{
    assert(v.size() == w.size());
    const int n = v.size();

    std::vector<std::vector<int>> memo = std::vector(n, std::vector(limit + 1, 0));
    for (int i = 0; i <= limit; ++i) {
        memo[0][i] = w[0] <= i ? v[0] : 0;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= limit; ++j) {
            if (j >= w[i])
                memo[i][j] = std::max(memo[i - 1][j], memo[i - 1][j - w[i]] + v[i]);
        }
    }

    return memo[n - 1][limit];
}
} // namespace algo
#endif // __KNAPSACK_H__
