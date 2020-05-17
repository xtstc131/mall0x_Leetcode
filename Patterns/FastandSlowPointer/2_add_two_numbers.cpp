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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto dummyHead = new ListNode(0);
        auto p = l1, q = l2;
        auto curr = dummyHead;
        int carry = 0;
        while (p != nullptr || q != nullptr)
        {
            int x = (p == nullptr) ? 0 : p->val;
            int y = (q == nullptr) ? 0 : q->val;
            int sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p)
                p = p->next;
            if (q)
                q = q->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};