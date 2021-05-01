// OJ: https://leetcode.com/problems/increasing-order-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* newroot, *current;
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        increasingBST(root->left);
        
        if (newroot == NULL){
            newroot = new TreeNode(root->val);
            current = newroot;
        }
        else{
            current->right = new TreeNode(root->val);
            current = current->right;
        }
        
        increasingBST(root->right);
        return newroot;
    }
};
