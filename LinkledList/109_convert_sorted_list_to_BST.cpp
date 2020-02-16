#include "header.hpp"
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode *fast = head, *slow = head, *last = slow;
        while (fast != nullptr && fast->next != nullptr)
        {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *righthead = slow->next;
        TreeNode *node = new TreeNode(slow->val);
        last->next = nullptr; // node before slow, cut the link

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(righthead);
        return node;
    }
};