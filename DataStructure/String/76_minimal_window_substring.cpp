#include "header.hpp"
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> letterCnt(128, 0);
        for (auto c : t)
            ++letterCnt[c];
        int left = 0, right = 0;
        int cnt = 0;
        int minLeft = -1;
        int minLength = INT_MAX;
        while (right <= s.size() - 1)
        {
            if (--letterCnt[s[right]] >= 0)
                cnt++;
            while (cnt == t.size())
            {
                if (minLength >= right - left + 1)
                {
                    minLength = right - left + 1;
                    minLeft = left;
                }
                if (++letterCnt[s[left]] > 0)
                    cnt--;
                left++;
            }
            right++;
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLength);
    }
};