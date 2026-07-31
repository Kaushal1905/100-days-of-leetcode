class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();

            if (--k == 0) return curr->val;

            curr = curr->right;
        }

        return -1;
    }
};