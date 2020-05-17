#include "header.hpp"
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int left, right, len;
        left = right = len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (right > left)
            {
                left = right = 0;
            }
            else if (right == left)
            {
                len = max(left * 2, len);
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if (left > right)
            {
                left = right = 0;
            }
            else if (right == left)
            {
                len = max(left * 2, len);
            }
        }
        return len;
    }
};