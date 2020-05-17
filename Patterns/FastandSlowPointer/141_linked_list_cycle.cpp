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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        auto first = head;
        auto second = head;
        while (first && first->next)
        {
            second = second->next;
            first = first->next->next;
            if (second == first)
                return true;
        }
        return false;
    }
};