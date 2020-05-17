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
        int pval = p->val;
        int qval = q->val;
        auto cur = root;
        while (true)
        {
            if (cur->val > pval && cur->val > qval)
            {
                cur = cur->left;
            }
            else if (cur->val < pval && cur->val < qval)
                cur = cur->right;
            else
            {
                break;
            }
        }
        return cur;
    }
};