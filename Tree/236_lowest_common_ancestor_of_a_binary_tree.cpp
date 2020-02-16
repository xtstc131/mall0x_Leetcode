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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q || root == nullptr)
            return root;
        auto p1 = lowestCommonAncestor(root->left, p, q);
        auto p2 = lowestCommonAncestor(root->right, p, q);
        if (p1 && p2)
            return root;
        return p1 ? p1 : p2;
    }
};