/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the next node's value into this node
        node->val = node->next->val;
        // Bypass the next node (effectively "deleting" it)
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;  // free memory, good practice in C++
    }
};