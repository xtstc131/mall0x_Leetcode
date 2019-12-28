#include"header.hpp"
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        vector<int> memo(n,INT_MAX);
        memo[0] = 0;
        for(int i = 0 ; i < m ; ++i)
            for(int j = 0 ; j < n ; ++j)
            {
                if(j == 0)
                {
                    memo[j] += grid[i][j];
                }
                else
                    memo[j] = min(memo[j],memo[j-1]) + grid[i][j];
            }
        return memo[n-1];
    }
};