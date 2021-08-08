// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            auto cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
        return ans;
    }
};
