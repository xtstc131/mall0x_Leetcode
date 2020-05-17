#include "header.hpp"
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    Node *connect(Node *root)
    {
        auto dummyHead = new Node(0);
        auto tmp = root;
        while (root)
        {
            auto cur = dummyHead;
            dummyHead->next = nullptr;
            while (root)
            {
                if (root->left)
                    //Cur has changed but cur->next still be root->left
                    cur = cur->next = root->left;
                if (root->right)
                    cur = cur->next = root->right;
                root = root->next;
            }
            root = dummyHead->next;
        }
        delete dummyHead;
        return tmp;
    }
};