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
    bool isPalindrome(ListNode *head)
    {
        auto fast = head;
        auto slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        fast = head;
        while (slow)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};