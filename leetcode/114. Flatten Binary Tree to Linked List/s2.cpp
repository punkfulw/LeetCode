// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root){
            if (root->left){
                TreeNode* p = root->left;
                while (p->right)
                    p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        return;
    }
};
