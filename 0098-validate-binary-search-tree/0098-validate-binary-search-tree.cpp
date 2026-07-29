class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long lower, long upper) {
        if (!node) return true;

        if (node->val <= lower || node->val >= upper) {
            return false;
        }

        return validate(node->left, lower, node->val) &&
               validate(node->right, node->val, upper);
    }
};