/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* store;

        while (head)
        {
            store = head->next;
            head->next = prev;
            prev = head;
            head = store;
        }
        return (prev);
    }

    void reorderList(ListNode* head)
    {
        ListNode* left = head;
        ListNode* right = head;

        while (right->next && right->next->next)
        {
            left = left->next;
            right = right->next->next;
        }
        right = left->next;
        left->next = nullptr;
        left = head;
        right = reverseList(right);
        while (right)
        {
            ListNode* store = right->next;

            right->next = left->next;
            left->next = right;
            left = right->next;
            right = store;
        }
    }
};
