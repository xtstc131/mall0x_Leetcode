#include "header.hpp"
class Solution
{
public:
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);

        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".")
                continue;
            if (tmp == ".." && !stk.empty())
                stk.pop_back();
            else if (tmp != "..")
                stk.push_back(tmp);
        }
        for (auto _path : stk)
        {
            res += ("/" + _path);
        }
        return res.empty() ? "/" : res;
    }
};