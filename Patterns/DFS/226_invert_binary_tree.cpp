#include "header.hpp"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            if (p)
            {
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left, p->right);
            }
        }
        return root;
    }
};