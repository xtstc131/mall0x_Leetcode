#include "header.hpp"
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 0)
            return false;
        int farthest = 0;
        for (int i = 0; i <= farthest && i < nums.size(); ++i)
        {
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= nums.size() - 1;
    }
};