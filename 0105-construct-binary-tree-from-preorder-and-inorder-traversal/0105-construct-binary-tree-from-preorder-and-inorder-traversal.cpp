class Solution {
public:
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, int preL, int preR, int inL, int inR) {
        if (preL > preR) return nullptr;

        int rootVal = preorder[preL];
        TreeNode* root = new TreeNode(rootVal);

        int inMid = inorderIndex[rootVal]; 
        int leftSize = inMid - inL;        

        root->left = build(preorder, preL + 1, preL + leftSize, inL, inMid - 1);
        root->right = build(preorder, preL + leftSize + 1, preR, inMid + 1, inR);

        return root;
    }
};