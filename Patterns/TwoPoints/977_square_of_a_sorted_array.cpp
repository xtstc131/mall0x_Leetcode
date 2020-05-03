#include "header.hpp"
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int l = 0;
        int r = A.size() - 1;
        vector<int> res(r + 1);
        int i = r;
        while (l <= r)
        {
            int l_square = A[l] * A[l];
            int r_square = A[r] * A[r];
            if (l_square >= r_square)
            {
                res[i--] = l_square;
                l++;
            }
            else
            {
                res[i--] = r_square;
                r--;
            }
        }
        return res;
    }
};