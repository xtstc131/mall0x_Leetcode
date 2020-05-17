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
    ListNode *swapPairs(ListNode *head)
    {
        auto dummy = new ListNode(0);   
        dummy->next = head;
        auto p1 = dummy;
        auto p2 = head;
        while (p2 != nullptr && p2->next != nullptr)
        {
            auto NextStart = p2->next->next;
            p1->next = p2->next; // dummy->next = 2
            p2->next->next = p2; //2->next = 1

            p2->next = NextStart; // 1->next = 3
            p1 = p2;              //
            p2 = p2->next;
        }
        return dummy->next;
    }
};