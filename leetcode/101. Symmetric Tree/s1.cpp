// OJ: https://leetcode.com/problems/symmetric-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return bfs(root, root);
    }
    bool bfs(TreeNode* r1, TreeNode* r2){
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2)
            return false;
        else{
            if (r1->val == r2->val){
                return bfs(r1->left, r2->right) && bfs(r1->right, r2->left);
                
            }
            else
                return false;
        }
        return false;
    }
};
