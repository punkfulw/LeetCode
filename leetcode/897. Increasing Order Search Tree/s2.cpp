// OJ: https://leetcode.com/problems/increasing-order-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    void helper(TreeNode* root, stack<TreeNode*> &stk) 
    {
        if (!root) return;
        helper(root->right, stk);
        stk.push(root);
        helper(root->left, stk);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> stk;
        helper(root, stk);
        TreeNode* dummy = new TreeNode(0), *p = dummy;
        while (!stk.empty())
        {
            p->right = stk.top(); stk.pop();
            p = p->right;
            p->left = NULL;
        }
        return dummy->right;
    }
};
