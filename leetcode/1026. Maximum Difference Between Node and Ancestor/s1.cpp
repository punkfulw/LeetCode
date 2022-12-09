// OJ: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int mx, int mn){
        if (!root)
            return;
        int a = abs(mx - root->val), b = abs(mn - root->val);
        ans = max(ans, max(a, b));
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        dfs(root->left, mx, mn);
        dfs(root->right, mx, mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
};
