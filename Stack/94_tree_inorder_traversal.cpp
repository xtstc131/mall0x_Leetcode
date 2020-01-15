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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>{};
        stack<TreeNode *> _stack;
        vector<int> res;
        auto cur = root;
        while (cur != nullptr || !_stack.empty())
        {
            while (cur != nullptr)
            {
                _stack.push(cur);
                cur = cur->left;
            }
            cur = _stack.top();
            _stack.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};