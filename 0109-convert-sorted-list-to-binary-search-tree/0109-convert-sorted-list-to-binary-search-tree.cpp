class Solution {
    ListNode* curr;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int size = 0;
        while (head) { size++; head = head->next; }
        return build(0, size - 1);
    }

private:
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* leftNode = build(left, mid - 1);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        root->left = leftNode;
        root->right = build(mid + 1, right);
        return root;
    }
};