// OJ: https://leetcode.com/problems/univalued-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isUnivalTree(TreeNode* root, int num = -1) {
        if (root == NULL)
            return true;
        if (num < 0)
            num = root->val;
        return (num == root->val && isUnivalTree(root->left, num) && isUnivalTree(root->right, num)); 
    }
};
