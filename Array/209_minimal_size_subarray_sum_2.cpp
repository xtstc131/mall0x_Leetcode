#include "header.hpp"
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int i = 0, j = -1;
        int sum = 0;
        int len = nums.size() + 1;
        while (i < nums.size())
        {
            if (j + 1 < nums.size() && sum < s)
                sum += nums[++j];
            else
                sum -= nums[i++];
            if (sum >= s && len > j - i + 1)
                len = j - i + 1;
        }
        if (len == nums.size() + 1)
            return 0;
        return len;
    }
};