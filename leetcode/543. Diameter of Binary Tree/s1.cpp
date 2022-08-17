// OJ: https://leetcode.com/problems/diameter-of-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans = 0;
    
    int dfs(TreeNode* root){
        if (!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        ans = max(ans, l + r);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
