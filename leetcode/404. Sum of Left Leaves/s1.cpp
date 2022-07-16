// OJ: https://leetcode.com/problems/sum-of-left-leaves
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int dfs(TreeNode* root, int d){
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return d == -1 ? root->val : 0;
        int l = dfs(root->left, -1), r = dfs(root->right, 1);
        return l + r;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 1);
    }
};
