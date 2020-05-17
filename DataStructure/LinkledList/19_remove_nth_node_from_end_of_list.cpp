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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto first = head;
        auto second = dummy;
        for (int i = 0; i < n; ++i)
            first = first->next;

        while (first != nullptr)
        {
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};