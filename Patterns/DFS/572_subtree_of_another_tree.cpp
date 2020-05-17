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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        ostringstream os1, os2;
        serialize(s, os1);
        serialize(t, os2);
        return os1.str().find(os2.str()) != string::npos;
    }
    void serialize(TreeNode *node, ostringstream &os)
    {
        if (!node)
            os << ",#";
        else
        {
            os << "," << node->val;
            serialize(node->left, os);
            serialize(node->right, os);
        }
    }
};