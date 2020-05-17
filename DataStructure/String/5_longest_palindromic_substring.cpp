#include "header.hpp"
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int maxLen = 0;
        int start = 0;

        //Annonymous Function, to avoid copy of string
        auto getLen = [&](int l, int r) {
            while (l >= 0 && r <= n - 1 && s[l] == s[r])
            {
                l--;
                r++;
            }
            return r - l - 1;
        };
        for (int i = 0; i < n; ++i)
        {
            int cur = max(getLen(i, i), getLen(i, i + 1));
            if (cur > maxLen)
            {
                maxLen = cur;
                start = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};