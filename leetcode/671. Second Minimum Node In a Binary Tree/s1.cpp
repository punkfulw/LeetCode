// OJ: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:

    int dfs(TreeNode* root, int mn){
        if (!root)
            return -1;
        if (root->val != mn)
            return root->val;
        int l = dfs(root->left, mn), r = dfs(root->right, mn);
        if (l == -1)
            return r;
        if (r == -1)
            return l;
        return min(l, r);
    }
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
};
