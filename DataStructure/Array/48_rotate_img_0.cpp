#include "header.hpp"
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int w = matrix.size();
        int h = w;
        int offset = w - 1;
        for (int i = 0; i < h; ++i)
        {
            for (int j = i + 1; j < w; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w / 2; ++j)
            {
                swap(matrix[i][j], matrix[i][offset - j]);
            }
        }
    }
};