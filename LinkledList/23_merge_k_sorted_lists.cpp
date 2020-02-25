#include "header.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int interval = 1;
        int amount = lists.size();
        if (amount == 0)
            return nullptr;
        while (interval < amount)
        {
            for (int i = 0; i < amount - interval; i += 2 * interval)
            {
                lists[i] = merge2Lists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        auto cur = head;
        while (l1 and l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return head->next;
    }
};