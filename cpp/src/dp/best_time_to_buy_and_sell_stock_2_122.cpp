#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        const int n = prices.size();

        // memo[i][j]: in ith day, whether hold a stock or not
        // if j == 1, then hold,
        // if j == 0, not hold
        vector<vector<int>> memo = vector(n + 1, vector(2, 0));

        memo[1][1] = -prices[0];

        for (int i = 2; i <= n; ++i) {
            // not hold has two situation:
            // 1. yesterday don't hold
            // 2. today sell
            memo[i][0]
                = std::max(memo[i - 1][0], memo[i - 1][1] + prices[i - 1]);
            // hold has two situation:
            // 1. yesterday hold
            // 2. today buy
            memo[i][1]
                = std::max(memo[i - 1][0] - prices[i - 1], memo[i - 1][1]);
        }

        // don't hold must be maximum
        return memo[n][0];
    }
};
