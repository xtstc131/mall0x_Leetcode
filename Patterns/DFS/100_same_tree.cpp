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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> _queue;
        _queue.push(p);
        _queue.push(q);

        while (!_queue.empty())
        {
            auto t1 = _queue.front();
            _queue.pop();
            auto t2 = _queue.front();
            _queue.pop();
            if (t1 == nullptr && t2 == nullptr)
                continue;
            if (t1 == nullptr || t2 == nullptr || t1->val != t2->val)
                return false;
            _queue.push(t1->left);
            _queue.push(t2->left);
            _queue.push(t1->right);
            _queue.push(t2->right);
        }
        return true;
    }
};