// OJ: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (!root)
            return ans;
        q.push(root);
        int cnt = 0;
        while (!q.empty()){
            int n = q.size();
            vector<int> cur(n);

            for (int i = 0; i < n; i++){
                auto node = q.front(); q.pop();
                if (cnt % 2)
                    cur[n - i - 1] = node->val;
                else
                    cur[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(cur);
            cnt++;
        }

        return ans;
    }
};
  
