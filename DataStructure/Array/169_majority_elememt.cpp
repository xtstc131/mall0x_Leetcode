#include "header.hpp"
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = 0;
        int result = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            if (res == 0)
                result = nums[i];
            if (nums[i] == result)
                res += 1;
            else
                res -= 1;
        }
        return result;
    }
};