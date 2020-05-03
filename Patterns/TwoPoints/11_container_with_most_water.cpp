#include "header.hpp"
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int num = height.size();
        int left = 0, right = num - 1;
        int maxArea = 0;
        while (left < right)
        {
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};