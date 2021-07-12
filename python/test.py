import collections
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        directions = [[0,1],[0,-1],[1,0], [-1,0]]
        def dfs(x, y):
            if (0 < x or x > m) or (0 < y or y > n) or grid[x][y]!='1':
                return
            grid[x][y] = '0'
            for direction in directions:
                deltax, deltay = direction
                dfs(x+deltax, y+deltay)
        count = 0                    
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    dfs(i,j)
                    count += 1
        return count