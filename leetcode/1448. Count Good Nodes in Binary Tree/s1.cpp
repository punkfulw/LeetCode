// OJ: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int mx = INT_MIN;
        
        helper(root, ans, mx);
        return ans;
    }
    void helper(TreeNode* root, int& ans, int mx){
        if (root->val >= mx){
            ans++;
            mx = root->val;
        }
        if (root->left) helper(root->left, ans, mx);
        if (root->right) helper(root->right, ans, mx);
        return;
    }
};
