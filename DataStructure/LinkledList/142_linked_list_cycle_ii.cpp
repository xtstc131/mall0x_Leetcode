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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        auto first = head;
        auto second = head;
        auto _head = head;
        bool hasCycle = false;
        while(first && first->next)
        {
            first = first->next->next;
            second = second->next;
            if(first == second)
            {
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle)
            return nullptr;
        while(_head != second)
        {
            _head = _head->next;
            second = second->next;
        }
        return second;
    }
};