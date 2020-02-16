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
    ListNode *deleteDuplicates(ListNode *head)
    {
       auto dummy = new ListNode(0);
       auto p = dummy;
        while(head)
        {
            bool flag = false;
            while(head->next && head->next->val == head->val)
            {
                head = head->next;
                flag = true;
            }
            if(flag)
            {
                p->next =   nullptr;
            }
            else
            {
                p = p->next = head;
            }
            head = head->next;
        }
        return dummy->next;
    
    }
};