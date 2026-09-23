class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
        return buildBST(values, 0, values.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& values, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(values[mid]);

        root->left = buildBST(values, left, mid - 1);
        root->right = buildBST(values, mid + 1, right);

        return root;
    }
};