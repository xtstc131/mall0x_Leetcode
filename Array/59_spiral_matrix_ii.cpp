#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> _r;
        if (n == 0)
            return _r;
        int u = 0, d = n - 1, l = 0, r = n - 1;
        vector<vector<int>> res(n, vector<int>(n));
        int i = 1;
        while (u <= d && l <= r)
        {
            for (int col = l; col <= r; col++)
            {
                res[u][col] = i++;
            }
            if (++u > d)
            {
                break;
            }
            for (int row = u; row <= d; row++)
            {
                res[row][r] = i++;
            }
            if (--r < l)
            {
                break;
            }
            for (int col = r; col >= l; col--)
            {
                res[d][col] = i++;
            }
            if (--d < u)
            {
                break;
            }
            for (int row = d; row >= u; row--)
            {
                res[row][l] = i++;
            }
            if (l++ > r)
            {
                break;
            }
        }
        return res;
    }
};