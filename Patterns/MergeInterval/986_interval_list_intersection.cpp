#include"header.hpp"
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int nA = A.size();
        int nB = B.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < nA && j < nB)
        {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi)
                res.push_back({lo, hi});

            if (A[i][1] < B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};