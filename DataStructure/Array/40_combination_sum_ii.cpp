#include "header.hpp"
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> _stack;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        helper(0, candidates, target);
        return res;
    }

    void helper(int index, vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            res.push_back(_stack);
            return;
        }
        else if (target < 0)
        {
            return;
        }
        else
        {
            for (int i = index; i < candidates.size(); ++i)
            {
                if (candidates[i] > target)
                    return; //Pruning, if candidates is larger than target, there is no need to create this branch, just return to save time.
                if (i > 0 && candidates[i] == candidates[i - 1] && i != index)
                    continue;
                _stack.push_back(candidates[i]);
                helper(i + 1, candidates, target - candidates[i]);
                _stack.pop_back();
            }
        }
    }
};