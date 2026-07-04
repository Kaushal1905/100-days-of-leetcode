class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // First leaf we hit = minimum depth
                if (!node->left && !node->right) {
                    return depth;
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        
        return depth;
    }
};