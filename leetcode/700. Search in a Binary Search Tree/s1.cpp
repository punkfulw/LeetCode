// OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val)
            return root;
        else if (root->val > val && root->left)
            return searchBST(root->left, val);
        else if (root->val < val && root->right)
            return searchBST(root->right, val);
        return NULL;
    }
};
