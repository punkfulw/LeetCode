// OJ: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            ans.push_back({});
            for (int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
