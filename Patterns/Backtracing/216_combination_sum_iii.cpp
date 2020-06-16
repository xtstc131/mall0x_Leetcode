#include "header.hpp"
class Solution
{

private:
    vector<int> tmp;
    vector<vector<int>> res;

public:
    void helper(int n, int k, int k_now, int start)
    {
        if (n == 0 && k_now == 0)
        {
            res.push_back(tmp);
            return;
        }
        if (n < 0 || k_now < 0)
            return;
        for (int i = start; i <= 9; ++i)
        {
            tmp.push_back(i);
            helper(n - i, k, k_now - 1, i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        helper(n, k, k, 1);
        return res;
    }
};