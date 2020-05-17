#include "header.hpp"
//  Definition for a binary tree node.
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        if (root == nullptr)
            return res;
        queue<TreeNode *> _queue;
        _queue.push(root);
        while (!_queue.empty())
        {
            int size = _queue.size();
            double _sum = 0;
            for (int i = 0; i < size; ++i)
            {
                auto node = _queue.front();
                _sum += node->val;
                _queue.pop();
                if (node->left)
                    _queue.push(node->left);
                if (node->right)
                    _queue.push(node->right);
            }
            res.push_back((double)_sum * 1.0 / size);
        }
        return res;
    }
};