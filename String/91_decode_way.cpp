#include "header.hpp"
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i++)
        {
            int one = stoi(s.substr(i - 1, 1));
            int two = stoi(s.substr(i - 2, 2));
            if (one >= 1)
                dp[i] += dp[i - 1];
            if (two >= 10 and two <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[s.length()];
    }
};