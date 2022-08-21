// OJ: https://leetcode.com/problems/print-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    
    int depth, col;
    int d(TreeNode* root){
        if (!root) return 0;
        int l = d(root->left), r = d(root->right);
        return max(l, r) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>> &ans, int row, int l, int r){
        if (!root) return;
        int mid = (l + r) / 2 ;
        ans[row][mid] = to_string(root->val);
        dfs(root->left, ans, row + 1, l, mid);
        dfs(root->right, ans, row + 1, mid + 1, r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        depth = d(root), col = pow(2, depth) - 1;
        vector<vector<string>> ans(depth, vector<string> (col));
        
        dfs(root, ans, 0, 0, col);
        return ans;
    }
};
