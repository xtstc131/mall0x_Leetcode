#include "header.hpp"
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto cur = head;
        while(cur)
        {
            if(cur->next && cur->next->val == cur->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return head;
    }
};