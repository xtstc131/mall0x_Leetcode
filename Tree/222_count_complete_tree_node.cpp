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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        auto l = root;
        auto r = root;
        int lh = 0;
        int rh = 0;
        while (l)
        {
            lh++;
            l = l->left;
        }
        while (r)
        {
            rh++;
            r = r->right;
        }
        if (lh == rh)
            return pow(2, lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};