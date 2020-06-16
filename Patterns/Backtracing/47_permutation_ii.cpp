#include"header.hpp"
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        // unordered_set<vector<int>> set;
        vector<int> path;
        int n = nums.size();
        vector<int> used(n);
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&](int d) {
            if (d == n)
            {
                res.push_back(path);
                return;
            }
            for (int i = 0; i < n; ++i)
            {
                if (used[i])
                    continue;
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                used[i] = 1;
                path.push_back(nums[i]);
                dfs(d + 1);
                path.pop_back();
                used[i] = 0;
            }
        };
        dfs(0);
        return res;
    }
};