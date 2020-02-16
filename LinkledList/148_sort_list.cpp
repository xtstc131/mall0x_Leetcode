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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        int len = 1;
        ListNode *cur = head;
        while (cur)
        {
            len++;
            cur = cur->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *l;
        ListNode *r;
        ListNode *tail;
        for (int i = 1; i < len; i <<= 1)
        {
            cur = dummy.next;
            tail = &dummy;
            while (cur)
            {
                l = cur;
                r = split(l, i);
                cur = split(r, i);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }

private:
    ListNode *split(ListNode *head, int n)
    {
        while (--n && head)
        {
            head = head->next;
        }
        ListNode *rest = head ? head->next : nullptr;
        if (head)
            head->next = nullptr;
        return rest;
    }
    pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next)
            tail = tail->next;
        return {dummy.next, tail};
    }
};