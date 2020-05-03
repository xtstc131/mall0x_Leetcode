#include"header.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(128, -1);
        int left = 0, right = 0;
        int res = 0;
        while (right < s.size())
        {
            left = max(left, dict[s[right]]);
            res = max(res, right - left + 1);
            dict[s[right]] = right + 1;
            right++;
        }
        return res;
    }
};