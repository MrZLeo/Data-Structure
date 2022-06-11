#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        const int n = nums.size();

        int sum = 0;
        for (auto num : nums)
            sum += num;

        if (std::abs(sum) < std::abs(target))
            return 0;

        int t = sum * 2 + 1;

        // memo[i][j]: use 1-ith num to get `sum - j`
        vector<vector<int>> memo = vector(n, vector(t, 0));

        if (nums[0] == 0)
            memo[0][sum] = 2;
        else {
            memo[0][sum + nums[0]] = 1;
            memo[0][sum - nums[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < t; ++j) {
                if (j >= nums[i])
                    memo[i][j] += memo[i - 1][j - nums[i]];
                if (j + nums[i] < t)
                    memo[i][j] += memo[i - 1][j + nums[i]];
            }
        }

        return memo[n - 1][sum + target];
    }
};
