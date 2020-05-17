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
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || !head->next || k == 0) return head; 
        int len = 1;
        auto node = head;
        while(node->next)
        {
            node = node->next;
            len++;
        }        
        k = k % len;
        int move = len - k;
        node->next = head;

        for(int i = 0; i < move; i++)
        {
            node = node->next;
        }
        head = node->next;
        node->next = nullptr;
        return head;
    }
};