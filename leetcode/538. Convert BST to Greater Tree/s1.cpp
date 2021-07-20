// OJ: https://leetcode.com/problems/convert-bst-to-greater-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int cnt = 0;
        helper(root, cnt);
        return root;
    }
    void helper(TreeNode* root, int& cnt){
        if (root != NULL){
            helper(root->right, cnt);
            cnt += root->val;
            root->val = cnt;
            helper(root->left, cnt);
        }
        return;
    }
};
