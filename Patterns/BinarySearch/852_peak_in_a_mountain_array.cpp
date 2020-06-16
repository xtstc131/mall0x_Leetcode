#include"header.hpp"
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int l = 0, r = A.size() - 1;
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (A[mid] < A[mid + 1])
                l = mid;
            else
                r = mid;
        }
        if (A[l] >= A[r])
            return l;
        else
            return r;
    }
};