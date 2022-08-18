// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<string> ans;
    
    void dfs(TreeNode* root, string s){
        s += to_string(root->val) + "->";
        if (!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
            return;
        }
        if (root->left)
            dfs(root->left, s);
        if (root->right)
            dfs(root->right, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
