/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                // Step 1: find rightmost node of left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                
                // Step 2: splice original right subtree onto rightmost
                rightmost->right = curr->right;
                
                // Step 3: move left subtree to right, clear left
                curr->right = curr->left;
                curr->left = nullptr;
            }
            
            // Step 4: move to next node
            curr = curr->right;
        }
    }
};