// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while (ans){
            if (ans->val > q->val && ans->val > p->val)
                ans = ans->left;
            else if (ans->val < q->val && ans->val < p->val)
                ans = ans->right;
            else
                break;
        }
        return ans;
    }
};
