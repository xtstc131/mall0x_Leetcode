#include "header.hpp"
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = INT_MIN;
        int min_cur = 1;
        int max_cur = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                swap(min_cur, max_cur);
            }
            min_cur = min(nums[i], min_cur * nums[i]);
            max_cur = max(nums[i], max_cur * nums[i]);
            res = max(max_cur, res);
        }
        return res;
    }
};