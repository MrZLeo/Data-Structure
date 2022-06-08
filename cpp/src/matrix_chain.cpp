#include "matrix_chain.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

void print_optimal(std::vector<std::vector<int>> &s, int i, int j)
{
    if (i == j) {
        std::cout << "A" << i;
        return;
    }

    std::cout << "(";
    print_optimal(s, i, s[i][j]);
    print_optimal(s, s[i][j] + 1, j);
    std::cout << ")";
}

/**
 * @algo matrix_chain
 *
 * @args p: each Ai = p_{i-1} * p_{i}
 */
int matrix_chain(std::vector<int> &p)
{
    // Ai = p_{i - 1} * p_{i}
    // An = p_{n - 1} * p_{n}
    // so p.size() == n + 1
    const int n = p.size() - 1;

    // memo[i][j] indicates that A[i, j]'s lowest calculate times
    std::vector<std::vector<int>> memo
        = std::vector(n + 1, std::vector(n + 1, INT32_MAX));

    // solu[i][j] shows that which k should be choose so that
    // A[i, k] * A[k, j] can be best answer
    std::vector<std::vector<int>> solu
        = std::vector(n + 1, std::vector(n + 1, 0));

    // A[i, i] cost 0 times to calculate because we just have one matrix
    // which don't need to compute
    for (int i = 0; i <= n; ++i) {
        memo[i][i] = 0;
    }

    // start from j - i == 1
    // l means the size of matrix this turn will compute
    // e.g. l == 2 means j - i + 1 == 2, i.e. m[i][j] contains 2 matrix
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1; // j - i == l - 1
            // i <= k < j
            // find the minimum sulution by computing each k
            // memo[i][k] and memo[k + 1][j] already calculted in the past
            for (int k = i; k < j; ++k) {
                int q = memo[i][k] + memo[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < memo[i][j]) {
                    memo[i][j] = q;
                    // if we need to find out the solution
                    // rather than the minimum, we need to
                    // store k in solu[i][j]
                    solu[i][j] = k;
                }
            }
        }
    }

    print_optimal(solu, 1, n);
    std::cout << std::endl;

    return memo[1][n];
}
