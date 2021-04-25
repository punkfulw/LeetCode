// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if  (root == nullptr)
            return root;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else {
            if (!root->left && !root->right){
                delete(root);
                return nullptr;
            }           
            if (!root->left || !root->right){
                TreeNode* child = root->left ? root->left : root->right;
                delete(root);
                return child;
            }
            if (root->left && root->right){
                TreeNode** pre = &(root->right);
                TreeNode* temp = root->right;
                while (temp->left){
                    pre = &(temp->left);
                    temp = temp->left;
                }
                root->val = temp->val;;  
                *pre = deleteNode(*pre, temp->val);
            }
        }
        return root;
    }
};
