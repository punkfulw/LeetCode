// OJ: https://leetcode.com/problems/binary-tree-tilt/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans = 0;
    int sol(TreeNode* root){
        if (!root)
            return 0;
        int l = sol(root->left), r = sol(root->right), sum = l + r + root->val;
        ans += abs(l - r);
        return sum;
    }
    int findTilt(TreeNode* root) {
        sol(root);
        return ans;
    }
};
