// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (!root)
            return ans;
        s.push(root);
        while (!s.empty()){
            auto cur = s.top();
            s.pop();
            ans.insert(ans.begin(), cur->val);
            if (cur->left)
                s.push(cur->left);
            if (cur->right)
                s.push(cur->right);
            
        }
        return ans;
    }
};
