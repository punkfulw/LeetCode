// OJ: https://leetcode.com/problems/recover-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* first, *second, *prev;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
      
        if (prev && root->val < prev->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        swap(first->val, second->val);
    }
};
