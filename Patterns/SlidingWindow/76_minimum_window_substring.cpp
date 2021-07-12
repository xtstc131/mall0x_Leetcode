#include "header.hpp"
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> dict(128, 0);
        for (auto c : t)
        {
            dict[c]++;
        }
        int left = 0, right = 0;
        int start = -1;
        int n = s.size();
        int cnt = 0;
        int nt = t.size();
        int min_length = INT_MAX;
        while (right < n)
        {
            if (--dict[s[right]] >= 0)
                cnt++;
            while (cnt == nt)
            {
                if (right - left + 1 < min_length)
                {
                    min_length = right - left + 1;
                    start = left;
                }

                if (++dict[s[left]] > 0)
                    cnt--;
                left++;
            }
            right++;
        }
        return start == -1 ? "" : s.substr(start, min_length);
    }
};