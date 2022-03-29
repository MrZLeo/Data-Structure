#include <cstdint>
#include <vector>
#include "matrix_chain.hpp"

/**
 * @algo matrix_chain
 *
 * @argu p: each Ai = p_{i-1} * p_{i}
 *
 *
 */
int matrix_chain(std::vector<int> &p) {
    const int n = p.size();
    std::vector<std::vector<int>> memo = std::vector(n + 1, std::vector(n + 1, INT32_MAX));
    std::vector<std::vector<int>> solu = std::vector(n + 1, std::vector(n + 1, 0));

    for (int i = 0; i <= n; ++i) {
        memo[i][i] = 0;
    }

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k < j; ++k) {
                int q = memo[i][k] + memo[k + 1][j] + p[i-1] * p[k] * p[j];
                if (q < memo[i][j]) {
                    memo[i][j] = q;
                    solu[i][j] = k;
                }
            }
        }
    }

    return memo[1][n - 1];
}
