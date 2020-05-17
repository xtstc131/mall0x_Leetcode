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
        if (head == nullptr)
            return;
        queue<ListNode *> _queue;
        stack<ListNode *> _stack;
        auto cur = head;
        int number = 0;
        while (cur)
        {
            number++;
            _queue.push(cur);
            _stack.push(cur);
            cur = cur->next;
        }
        auto node_0 = _queue.front();
        auto node_1 = _queue.front();
        ;
        for (int i = 0; i < number; ++i)
        {
            if (i % 2 == 0)
            {
                node_0 = _queue.front();
                _queue.pop();
            }
            else
            {
                node_0 = _stack.top();
                _stack.pop();
            }
            if (i != 0)
                node_1->next = node_0;
            node_1 = node_0;
        }
        node_0->next = nullptr;
    }
};