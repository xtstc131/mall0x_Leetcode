#include "header.hpp"
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        auto cur = head;
        ListNode dummy(0);
        auto _head = &dummy;
        auto pre = &dummy;
        _head->next = head;
        while (cur)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
            }
            else
                pre = cur;
            cur = cur->next;
        }
        return _head->next;
    }
};