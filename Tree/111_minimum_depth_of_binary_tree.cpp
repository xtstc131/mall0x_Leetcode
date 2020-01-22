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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> BFS;
        BFS.push(root);
        int depth = 0;
        while (!BFS.empty())
        {
            auto size = BFS.size();
            depth++;
            for (int i = 0; i < size; ++i)
            {
                auto cur = BFS.front();
                if (!cur->left && !cur->right)
                    return depth;
                BFS.pop();
                if (cur->left)
                    BFS.push(cur->left);
                if (cur->right)
                    BFS.push(cur->right);
            }
        }
        return depth;
    }
};