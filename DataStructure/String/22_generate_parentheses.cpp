#include "header.hpp"
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        helper(res, "", 0, n);
        return res;
    }
    void helper(vector<string> &res, string str, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            res.push_back(str);
        }
        if (m > 0)
            helper(res, str + ")", m - 1, n);
        if (n > 0)
            helper(res, str + "(", m + 1, n - 1);
    }
};