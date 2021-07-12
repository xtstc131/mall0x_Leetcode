#include "header.hpp"
class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int start_x = 0;
        int start_y = 0;
        int non_obstacles = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
                if (grid[i][j] >= 0)
                    non_obstacles++;
            }
        dfs(start_x, start_y, grid, non_obstacles);
        return res;
    }

    void dfs(int x, int y, vector<vector<int>> &grid, int remain)
    {
        int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (grid[x][y] == 2 && remain == 1)
        {
            res++;
            return;
        }
        auto tmp = grid[x][y];
        grid[x][y] = -4;
        remain--;
        for (int i = 0; i < 4; ++i)
        {
            if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] < 0)
                continue;
            auto new_x = x + direction[i][0];
            auto new_y = y + direction[i][1];
            dfs(new_x, new_y, grid, remain);
        }
        grid[x][y] = tmp;
    }

private:
    int res;
};