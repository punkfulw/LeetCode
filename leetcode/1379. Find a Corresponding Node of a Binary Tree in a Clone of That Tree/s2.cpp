// OJ: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* t;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned != NULL){
            if (cloned->val == target->val)
                t = cloned;
            getTargetCopy(original, cloned->left, target);
            getTargetCopy(original, cloned->right, target);
        }
        return t;
    }
};
