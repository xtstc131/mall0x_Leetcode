#include "header.hpp"
class Solution
{
private:
    vector<vector<int>> ans;
    

public:
    void dfs(int nowIndex, int nowSum, vector<int> cand, int candSize, int target)
    {
        if (nowSum > target)
            return;
        if (nowSum == target)
        {
            ans.push_back(rs);
            return;
        }
        for (int i = nowIndex; i < candSize; i++)
        {
            if (nowSum + cand[i] <= target)
            {
                rs.push_back(cand[i]);
                dfs(i, nowSum + cand[i], cand, candSize, target);
                rs.pop_back(); // backtracing
            }
            else
                continue;
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int len = candidates.size();
        if (len == 0)
            return ans;
        dfs(0, 0, candidates, len, target);
        return ans;
    }
};
