#include "header.hpp"
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int left, right, up, down;
        int m = matrix.size();
        int n = matrix[0].size();
        right = n - 1;
        down = m - 1;
        left = n - 1;
        up = m - 2;
        int i = 0;
        int j = 0;
        bool first_time = true;
        while (true)
        {
            if (!first_time && right <= 0)
                break;
            if (first_time)
            {
                for (int _j = j; _j <= j + right; _j++)
                {
                    res.push_back(matrix[i][_j]);
                }
            }
            else
            {
                for (int _j = j; _j < j + right; _j++)
                {
                    res.push_back(matrix[i][_j]);
                }
            }
            if (first_time)
                j += right;
            else
            {
                j += (right - 1);
            }
            i++;
            if (first_time)
            {
                right--;
                first_time = false;
            }
            else
            {
                right -= 2;
            }
            if (down <= 0)
                break;
            for (int _i = i; _i < i + down; _i++)
            {
                res.push_back(matrix[_i][j]);
            }
            i += (down - 1);
            j--;
            down -= 2;

            if (left <= 0)
                break;
            for (int _j = j; _j > j - left; --_j)
            {
                res.push_back(matrix[i][_j]);
            }
            j -= (left - 1);
            i--;
            left -= 2;

            if (up <= 0)
                break;
            for (int _i = i; _i > i - up; --_i)
            {
                res.push_back(matrix[_i][j]);
            }
            i -= (up - 1);
            j++;
            up -= 2;
        }
        return res;
    }
};