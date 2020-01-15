#include "header.hpp"
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> _stack;
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
                _stack.push(')');
                break;
            case '{':
                _stack.push('}');
                break;
            case '[':
                _stack.push(']');
                break;
            default:
                if (_stack.empty() || _stack.top() != c)
                    return false;
                else
                    _stack.pop();
            }
        }
        return _stack.empty();
    }
};