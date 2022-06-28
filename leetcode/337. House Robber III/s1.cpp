// OJ: https://leetcode.com/problems/house-robber-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if (!root)
            return {0, 0};
        if (!root->left && !root->right)
            return {0, root->val};
        pair<int, int> l = dfs(root->left), r = dfs(root->right);
        return {max(l.first, l.second) + max(r.first, r.second), root->val + l.first + r.first};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
