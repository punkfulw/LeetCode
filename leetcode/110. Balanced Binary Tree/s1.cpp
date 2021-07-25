// OJ: https://leetcode.com/problems/balanced-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool check = true;
        int c = dfs(root, check);
        return check;
    }
    int dfs(TreeNode* root, bool& check){
        if (!root)
            return 0;
        int l = dfs(root->left, check);
        int r = dfs(root->right, check);
        if (abs(l - r) > 1)
            check = false;
        return max(l, r)+1;
    }
};
