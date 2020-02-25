#include "header.hpp"
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> memo(nums.size() + 1, 0);
        memo[0] = 0;
        memo[1] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            memo[i + 1] = max(memo[i - 1] + nums[i], memo[i]);
        }
        return memo[nums.size()];
    }
};