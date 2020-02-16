#include "header.hpp"
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        result.push_back("");
        static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i)
        {
            int num = digits[i] - '0';
            if (num > 9 || num < 0)
                break;
            auto candidate = v[num];
            vector<string> tmp;
            for (int j = 0; j < candidate.size(); ++j)
                for (int k = 0; k < result.size(); ++k)
                {
                    tmp.push_back(result[k] + candidate[j]);
                }
            result.swap(tmp);
        }
        return result;
    }
};