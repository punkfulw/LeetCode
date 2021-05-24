// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorder(TreeNode* root, vector<int>& ans){
        if (root != NULL){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return inorder(root, ans);
    }
};
