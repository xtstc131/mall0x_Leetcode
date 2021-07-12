#include "header.hpp"
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> dict(128, 0);
        for (auto &c : s1)
            dict[c]++; // 记录 出现次数的差值

        int l = 0, r = 0;
        while (r < s2.size())
        {
            char c = s2[r++];
            dict[c]--; // 入窗
            while (l < r && dict[c] < 0)
            { // 出窗
                dict[s2[l++]]++;
            }
            if (r - l == s1.size())
                return true;
        }
        return false;
    }

    // Using cnt
    // bool checkInclusion(string s1, string s2)
    // {
    //     vector<int> dict(128, 0);
    //     for (auto &c : s1)
    //         dict[c]++; // 记录 出现次数的差值
    //     int n = s2.size();
    //     int nt = s1.size();
    //     int left = 0, right = 0;
    //     int cnt = 0;
    //     while (right < n)
    //     {
    //         if (--dict[s2[right]] >= 0)
    //             cnt++;
    //         while (cnt == nt)
    //         {
    //             if (right - left + 1 == nt)
    //                 return true;
    //             if (++dict[s2[left]] > 0)
    //                 cnt--;
    //             left++;
    //         }
    //         right++;
    //     }
    //     return false;
    // }
};