// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int depth = 0;
    TreeNode* ans;
    int dfs(TreeNode* root){
        if (!root)
            return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
    }
    
    int sol(TreeNode* root, int cnt){
        if (!root)
            return 0;
        if (cnt == depth){
            ans = root;
            return 1;
        }
        int l = sol(root->left, cnt + 1), r = sol(root->right, cnt + 1);
        if (l && r)
            ans = root;
        return l || r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth = dfs(root) - 1;
        sol(root, 0);
        return ans;
    }
};
