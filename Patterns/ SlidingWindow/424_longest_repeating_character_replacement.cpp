#include "header.hpp"
class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        int left = 0, right = 0;
        int n = s.size();
        int max_count = INT_MIN;
        int res = 0;
        vector<int> count(26, 0);
        while (right < n)
        {
            max_count = max(max_count, ++count[s[right] - 'A']);

            while (right - left + 1 - max_count > k)
            {
                --count[s[left++] - 'A'];
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};