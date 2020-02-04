#include "header.hpp"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator
{
public:
    stack<TreeNode *> _stack;
    BSTIterator(TreeNode *root)
    {
        _leftmostInorder(root);
    }
    void _leftmostInorder(TreeNode *root)
    {
        while (root)
        {
            _stack.push(root);
            root = root->left;
        }
    }
    /** @return the next smallest number */
    int next()
    {
        auto cur = _stack.top();
        _stack.pop();

        if (cur->right)
        {
            _leftmostInorder(cur->right);
        }
        return cur->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !_stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */