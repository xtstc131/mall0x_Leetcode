#include "header.hpp"
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int mSize = matrix.size();
        reverse(matrix.begin(), matrix.end()); // first flip
        for (int i = 0; i < mSize; ++i)
        { // second flip
            for (int j = i + 1; j < mSize; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};