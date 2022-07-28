// OJ: https://leetcode.com/problems/path-sum-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int tar, vector<int> &path){
        if (!root)
            return;
        path.push_back(root->val);
        tar -= root->val;
        if (tar == 0 && !root->right && !root->left)
            ans.push_back(path);
        if (root->left)
            dfs(root->left, tar, path);
        if (root->right)
            dfs(root->right, tar, path);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<int> path;
        dfs(root, tar, path);
        return ans;
    }
};
