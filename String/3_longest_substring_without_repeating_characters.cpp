#include "header.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> dict(128, -1);
        int maxLength = 0;
        int start = -1;
        for (int i = 0; i < s.length(); ++i)
        {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};