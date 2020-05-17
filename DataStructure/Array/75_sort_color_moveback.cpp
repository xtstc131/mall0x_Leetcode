#include "header.hpp"
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = -1; // Last position of 0
        int j = -1; // Last position of 1
        int k = -1; // Last position of 2
        int n = nums.size();
        for (int p = 0; p < n; p++)
        {
            //根据第i个数字，挪动0~i-1串。
            if (nums[p] == 0)
            {
                nums[++k] = 2; //2往后挪
                nums[++j] = 1; //1往后挪
                nums[++i] = 0; //0往后挪
            }
            else if (nums[p] == 1)
            {
                nums[++k] = 2;
                nums[++j] = 1;
            }
            else
                nums[++k] = 2;
        }
    }
};