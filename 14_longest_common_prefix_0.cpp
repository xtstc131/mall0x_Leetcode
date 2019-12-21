#include<string>
#include<vector>
using namespace std;
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string laststr;
        string ans;
        int str_size, laststr_size;
        laststr = strs[0];
        for (auto str : strs){
            ans = "";
            str_size = str.size();
            laststr_size = laststr.size();

            for (int i =0; i < min(str_size, laststr_size); i++){
                if (str[i] == laststr[i])
                    ans += str[i];
                else
                    break;
            }
            laststr = ans;

        }
        return ans;
    }
};