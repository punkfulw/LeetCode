// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    queue<TreeNode*> q;
    void sol(TreeNode* root){
        if (!root)
            return;
        q.push(root);
        sol(root->left);
        sol(root->right);
    }
    
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        if (!root)
            return;
        TreeNode* dummy = new TreeNode(0), *pre = dummy;
        sol(root);
        while (!q.empty()){
            auto node = q.front();
            q.pop();
            pre->right = node;
            pre = node;
            node->left = NULL;
        }
        return;
    }
};
