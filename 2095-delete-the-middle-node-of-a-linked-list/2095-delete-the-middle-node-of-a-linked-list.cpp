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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next->next;  // offset fast by 2 to track prev of middle

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now just BEFORE the middle node
        slow->next = slow->next->next;  // delete middle

        return head;
    }
};