#include"header.hpp"
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0)
                continue;

            if (i > 0 && (nums[i] == nums[i - 1]))
                continue; // to avoid duplicates
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else
                {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l + 1])
                        l++; // to avoid duplicates
                    while (l < r - 1 && nums[r] == nums[r - 1])
                        r--; // to avoid duplicates
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};