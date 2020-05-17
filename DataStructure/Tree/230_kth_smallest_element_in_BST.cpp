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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> _stack;
        while (true)
        {
            while (root != nullptr)
            {
                _stack.push(root);
                root = root->left;
            }
            root = _stack.top();
            _stack.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
    }
};