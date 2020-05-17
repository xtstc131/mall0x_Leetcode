#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if (n < 4)
            return ans;
        for (int i = 0; i < n - 3; i++)
        {
            if (target <= 0 and nums[i] > 0)
                break;
            // nums[i] has become too large, no point in continuing
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            // nums[i] is so small, even the largest elements cannot help reach the sum
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            // skip duplicates
            if (i > 0 && (nums[i] == nums[i - 1]))
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                /* Some more pruning */
                // nums[j] has become too large, no point in continuing
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                // nums[j] is so small, even the largest elements cannot help reach the sum
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int l = j + 1;
                int r = n - 1;
                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                        l++;
                    else if (nums[i] + nums[j] + nums[l] + nums[r] > target)
                        r--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l] == nums[l + 1])
                            l++;
                        while (r - 1 > l && nums[r] == nums[r - 1])
                            r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};