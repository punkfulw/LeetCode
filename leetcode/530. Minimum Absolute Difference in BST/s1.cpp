// OJ: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/99938/C%2B%2B-O(n)-or-O(h)
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        return helper(root, pre, ans);
    }
    int helper (TreeNode* root, int& pre, int& ans){
        if (root->left != NULL)
            helper(root->left, pre, ans);
        if (pre >= 0)
            ans = min(ans, root->val - pre);
        pre = root->val;
        if (root->right != NULL)
            helper(root->right, pre, ans);
        return ans;
    }
};
