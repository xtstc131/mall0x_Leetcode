#include "header.hpp"
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums.size() < 2)
        {
            if (nums.size() > 0 && nums[0] == target)
                return vector<int>{0, 0};
            else
                return vector<int>{-1, -1};
        }
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (target == nums[mid])
            {
                auto index_1 = mid;
                auto index_2 = mid;
                while (index_1 + 1 < nums.size() && nums[index_1 + 1] == nums[index_1])
                    index_1++;
                while (index_2 - 1 >= 0 && nums[index_2 - 1] == nums[index_2])
                    index_2--;
                return vector<int>{index_2, index_1};
            }
            else if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return vector<int>{-1, -1};
        ;
    }
};