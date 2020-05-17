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
        auto result = head;
        auto lastone = cur;
        auto node_before = head;
        auto node_first_rev = head;
        int index = 1;

        while (cur)
        {
            auto tmp = cur->next;
            if (index == m - 1)
                node_before = cur;
            if (index >= m && index <= n)
            {
                if (index == m)
                {
                    node_first_rev = cur;
                }
                else if (index == n)
                {
                    if (m == 1)
                    {
                        result = cur;
                    }
                    node_before->next = cur;
                    node_first_rev->next = cur->next;
                    cur->next = lastone;
                }
                else
                {
                    cur->next = lastone;
                }
            }
            index++;
            lastone = cur;
            cur = tmp;
        }
        return result;
    }
};
