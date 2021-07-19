// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (!root)
            return ans;
        q.push(root);
        while (q.size()){
            int n = q.size();
            int mx = INT_MIN;
            for (int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                mx = max(mx, cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
