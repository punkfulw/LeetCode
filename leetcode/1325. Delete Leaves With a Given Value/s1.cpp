// OJ: https://leetcode.com/problems/delete-leaves-with-a-given-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* sol(TreeNode *root, int &tar){
        if (!root) return NULL;
        root->left = sol(root->left, tar);
        root->right = sol(root->right, tar);
        if (!root->left && !root->right && root->val == tar)
            return NULL;
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return sol(root, target);
    }
};
