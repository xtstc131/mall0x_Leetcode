#include "header.hpp"
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int start = 0;
        int count = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            while (sum >= s)
            {
                sum -= nums[start];
                count = min(count, i - start + 1);
                start++;
            }
        }
        return count == INT_MAX ? 0 : count;
    }
};