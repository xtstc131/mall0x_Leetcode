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
        if (!head || !(head->next))
            return head;

        //get the linked list's length
        ListNode *cur = head;
        int length = 0;
        while (cur)
        {
            length++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1)
        {
            cur = dummy.next;
            tail = &dummy;
            while (cur)
            {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }

private:
    /**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
    ListNode *split(ListNode *head, int n)
    {
        //if(!head) return NULL;
        for (int i = 1; head && i < n; i++)
            head = head->next;

        if (!head)
            return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head)
    {
        ListNode *cur = head;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
                swap(l1, l2);
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        cur->next = (l1 ? l1 : l2);
        while (cur->next)
            cur = cur->next;
        return cur;
    }
};