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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == 1 && n == 1)
            return head;

        auto cur = head;
        ListNode *pre = nullptr;
        while (m > 1)
        {
            pre = cur;
            cur = cur->next;
            m--;
            n--;
        }
        auto con = pre;
        auto tail = cur;

        ListNode *temp = nullptr;

        while (n)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            n--;
        }

        if (con)
        {
            con->next = pre;
        }
        else
            head = pre;

        tail->next = cur;
        return head;
    }
};
