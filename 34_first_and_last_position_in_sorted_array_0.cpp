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
            {
                vector<int> result = {0, 0};
                return result;
            }
            else
            {
                vector<int> result = {-1, -1};
                return result;
            }
        }
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
            {
                auto index_1 = mid;
                auto index_2 = mid;
                while (index_1 + 1 < nums.size() && nums[index_1 + 1] == nums[index_1])
                    index_1++;
                while (index_2 - 1 >= 0 && nums[index_2 - 1] == nums[index_2])
                    index_2--;
                vector<int> result = {index_2, index_1};
                return result;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        vector<int> result = {-1, -1};
        return result;
    }
};