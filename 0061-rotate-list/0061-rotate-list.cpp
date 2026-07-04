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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int length = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            length++;
        }

        k = k % length;

        if (k == 0) {
            return head;
        }

        tail->next = head;   // make circular list

        int steps = length - k;
        ListNode* newTail = tail;

        while (steps--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};