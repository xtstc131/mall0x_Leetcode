#include "header.hpp"
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
            {
                bool firstMatch = (i < m && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < n && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        return dp[0][0];
    }
};