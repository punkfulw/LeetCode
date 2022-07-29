// OJ: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(log(N))
class Solution {
public:
    int ans = INT_MAX;
    
    void dfs(TreeNode* root, int &pre){
        if (!root)
            return;
        dfs(root->left, pre);
        ans = min(ans, root->val - pre);
        pre = root->val;
        dfs(root->right, pre);
    }
    
    int minDiffInBST(TreeNode* root) {
        int pre = -100000;
        dfs(root, pre);
        return ans;
    }
};
