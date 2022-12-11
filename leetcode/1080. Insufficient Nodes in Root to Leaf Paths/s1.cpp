// OJ: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sol(TreeNode* root, int limit){
        limit -= root->val;
        
        if (!root->left && !root->right)
            return limit <= 0;
        int l = 0, r = 0;
        
        if (root->left)
            l = sol(root->left, limit);
        if (root->right)
            r = sol(root->right, limit);
        if (!l)
            root->left = NULL;
        if (!r)
            root->right = NULL;
        return l || r;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        return sol(root, limit) ? dummy->left : NULL;
    }
};
