class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> num_stack;
        // stack<char> operator_stack;
        for (auto s : tokens)
        {
            char c = s[0];
            if (s.size() > 1 || isdigit(s[0]))
            {
                num_stack.push(stoi(s));
                continue;
            }
            else
            {
                int a = num_stack.top();
                num_stack.pop();
                int b = num_stack.top();
                num_stack.pop();
                int num = 0;
                switch (c)
                {
                case '+':
                    num = a + b;
                    break;
                case '-':
                    num = b - a;
                    break;
                case '*':
                    num = a * b;
                    break;
                case '/':
                    num = b / a;
                    break;
                default:
                    break;
                }
                num_stack.push(num);
            }
        }
        return num_stack.empty() ? 0 : num_stack.top();
    }
};