#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> Pstack;
        for(auto c : s){
            switch(c)
            {
                case '(':
                case '[':
                case '{':
                    Pstack.push(c);
                    break;
                case ')': 
                    if(Pstack.empty() || Pstack.top() != '(') return false; 
                    else 
                        Pstack.pop();
                    break;
                case ']':
                    if(Pstack.empty() || Pstack.top() != '[') return false; 
                    else 
                        Pstack.pop();
                    break;
                case '}': 
                    if(Pstack.empty() || Pstack.top() != '{') return false; 
                    else 
                        Pstack.pop();
                    break;
            }
        }
        return Pstack.empty();
    }
};