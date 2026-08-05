class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        int maxVal = curr->val;

        while (curr->next) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next;
            } else {
                maxVal = curr->next->val;
                curr = curr->next;
            }
        }
        return reverse(head);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};