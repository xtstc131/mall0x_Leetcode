#include"header.hpp"
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;

        if (target < matrix[0][0] || target > matrix.back().back())
            return false;

        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n; //NOTE: right init as m * n, thus search within interval [left, right) 左闭右开

        while (left < right)
        { //NOTE: <
            int mid = left + (right - left) / 2;

            int val = matrix[mid / n][mid % n];

            if (val == target)
                return true;
            else if (val < target)
                left = mid + 1;
            else
                right = mid; //NOTE: mid
        }

        return false;
    }
};