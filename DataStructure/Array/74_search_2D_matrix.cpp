#include "header.hpp"
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            int num = matrix[i][j];
            if (num == target)
                return true;
            else if (num > target)
                i--;
            else
                j++;
        }
        return false;
    }
};