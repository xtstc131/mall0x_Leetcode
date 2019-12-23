class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans;
        int min = INT_MAX;
        for (int i = 0; i < n - 2; ++i)
        {
            auto l = i + 1;
            auto r = n - 1;
            while (l < r)
            {
                auto sum = nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < min)
                {
                    min = abs(sum - target);
                    ans = sum;
                }
                if (sum < target)
                    l++; //
                else if (sum > target)
                    r--;
                else
                {
                    return sum;
                }
            }
        }
        return ans;
    }
};