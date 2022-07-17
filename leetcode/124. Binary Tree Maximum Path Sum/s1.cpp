// OJ: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans = INT_MIN; 
    int dfs(TreeNode* root){
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        int cur = root->val + l + r;
        ans = max(ans, cur);
        return max({0, cur - l, cur - r});
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
