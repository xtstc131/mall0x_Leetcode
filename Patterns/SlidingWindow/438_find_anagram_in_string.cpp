#include "header.hpp"
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> dict(128);
        for (auto c : p)
        {
            dict[c]++;
        }
        vector<int> res;
        int begin = 0, end = 0;
        int cnt = p.size();
        int n = s.size();
        int pn = 0;
        while (end < n)
        {
            if (--dict[s[end]] >= 0)
                pn++;
            while (pn == cnt)
            {
                if (++dict[s[begin]] > 0)
                    pn--;
                if (end - begin == cnt - 1)
                    res.push_back(begin);
                begin++;
            }
            end++;
        }
        return res;
    }
};