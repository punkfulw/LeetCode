// OJ: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int helper(TreeNode* root, int sum = 0){
        if (root == NULL)
            return 0;
        sum = sum * 2 + root->val;
        return root->left == root->right? sum : helper(root->left, sum) + helper(root->right, sum);
            
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root);
    }
};
