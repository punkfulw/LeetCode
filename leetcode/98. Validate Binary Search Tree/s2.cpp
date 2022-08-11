// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool ans = true;
    void dfs(TreeNode* root, long &pre){
        if (!root || !ans) return;
        dfs(root->left, pre);
        if (root->val <= pre) ans = false;
        pre = root->val;
        dfs(root->right, pre);
    }
    bool isValidBST(TreeNode* root) {
        long pre = (long)INT_MIN - 1;
        dfs(root, pre);
        return ans;
    }
};
