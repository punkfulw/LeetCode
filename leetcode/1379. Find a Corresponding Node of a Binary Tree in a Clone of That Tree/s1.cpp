// OJ: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == NULL)
            return NULL;
        if (cloned->val == target->val)
            return cloned;
        
        TreeNode* ans = getTargetCopy(original->left, cloned->left, target);
        return ans ? ans : getTargetCopy(original->right, cloned->right, target);

    }
};
