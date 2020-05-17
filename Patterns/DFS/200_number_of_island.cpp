#include "header.hpp"
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        if (m == 0 || n == 0)
            return 0;
        int count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    eraseland(grid, i, j);
                }
            }
        return count;
    }

    void eraseland(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 or i == m or j < 0 or j == n or grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        eraseland(grid, i - 1, j);
        eraseland(grid, i + 1, j);
        eraseland(grid, i, j - 1);
        eraseland(grid, i, j + 1);
    }
};