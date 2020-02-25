#include"header.hpp"
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0)
            return 0;
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0 ; i < m ; ++i)
            for(int j = 0; j < n; ++j)
            {
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j] == 0)
                    continue;
                if(i != 0 and j!=0)
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),
                                   dp[i-1][j-1]) + 1;
                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        return ans;
    }
};