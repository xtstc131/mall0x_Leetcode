#include "header.hpp"
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (wordDict.size() == 0)
            return false;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] == true)
                {
                    string substring = s.substr(j, i - j);
                    if (find(wordDict.begin(), wordDict.end(), substring) != wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        return dp[s.size()];
    }
};