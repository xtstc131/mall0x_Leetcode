#include"header.hpp"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int num = height.size();
        int begin = 0;
        int end = num - 1;
        int area = 0;
        for (auto i = 0; i < num; ++i)
        {
            auto left = height[begin];
            auto right = height[end];
            int _area = 0;
            int h = 0;

            if (left >= h && left <= right)
            {
                h = left;
                _area = h * (end - begin);
                begin++;
            }
            else if (right >= h && left > right)
            {
                h = right;
                _area = h * (end - begin);
                end--;
            }
            if (_area > area)
                area = _area;

            if (end <= begin)
                break;
        }
        return area;
    }
};