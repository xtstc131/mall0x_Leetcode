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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> _stack;
        auto cur = root;
        long inorder = LONG_MIN; //To handle INT_MAX and INT_MIN; if don't use this value,
                                 //funciotn will return false
        while (!_stack.empty() || cur != nullptr)
        {
            while (cur != nullptr)
            {
                _stack.push(cur);
                cur = cur->left;
            }
            cur = _stack.top();
            _stack.pop();
            if (cur->val <= inorder)
                return false;
            inorder = cur->val;
            cur = cur->right;
        }
        return true;
    }
};