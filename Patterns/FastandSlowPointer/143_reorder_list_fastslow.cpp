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
    void reorderList(ListNode *head)
    {

        auto fast = head;
        auto slow = head;
        if (!head || !(head->next))
        { // if the list is empty or only has one element
            return;
        }
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *preNode = nullptr;
        //Start of second part
        ListNode *cur = slow->next;
        //Cut
        slow->next = nullptr;
        ListNode *tmp;
        while (cur)
        {
            tmp = cur->next;
            cur->next = preNode;
            preNode = cur;
            cur = tmp;
        }
        auto head1 = head;
        auto head2 = preNode;
        while (head2)
        {
            tmp = head1->next;
            head1 = head1->next = head2;
            head2 = tmp;
        }
    }
};