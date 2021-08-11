// OJ: https://leetcode.com/problems/flip-equivalent-binary-trees/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if (!r1 & !r2)
            return true;
        if (r1 && r2){
            if (r1->val == r2->val){
                bool l = flipEquiv(r1->left, r2->left) || flipEquiv(r1->left, r2->right);
                bool r = flipEquiv(r1->right, r2->left) || flipEquiv(r1->right, r2->right);
                return l && r;
            }
        }
        return false;
    }
};
