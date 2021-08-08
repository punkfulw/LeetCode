// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>  ans;
        dfs(root, ans);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& ans){
        if (root != NULL){
            ans.push_back(root->val);
            dfs(root->left, ans);
            dfs(root->right, ans);
        }
        return;
    }
};
