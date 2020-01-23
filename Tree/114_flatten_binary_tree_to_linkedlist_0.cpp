#include "header.hpp"
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        stack<TreeNode*> s;
        s.push(root);
        
        TreeNode* prev = nullptr;
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            
            if (prev)
            {
                prev->left = nullptr;
                prev->right = node;
            }
            
            prev = node;
            
            if (node->right)
                s.push(node->right);
            if (node->left)
                s.push(node->left);
        }
    }
};