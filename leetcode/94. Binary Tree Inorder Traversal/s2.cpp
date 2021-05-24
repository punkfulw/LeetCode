// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> todo;
        
        while (!todo.empty() || root){
            while (root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            ans.push_back(root->val);
            todo.pop();
            root = root->right;
        }
        return ans;
    }
};
