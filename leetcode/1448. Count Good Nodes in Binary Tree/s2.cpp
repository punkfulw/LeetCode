// OJ: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans = 0;
    
    void sol(TreeNode* root, int mx){
        if (!root)
            return;
        if (root->val >= mx)
            ans++;
        mx = max(mx, root->val);
        sol(root->left, mx);
        sol(root->right, mx);
    }
    
    int goodNodes(TreeNode* root) {
        sol(root, INT_MIN);
        return ans;
    }
};
