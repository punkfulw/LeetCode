// OJ: https://leetcode.com/problems/same-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        else{
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
