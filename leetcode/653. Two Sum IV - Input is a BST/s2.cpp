// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            auto node = q.front(); q.pop();
            int num = node->val;
            if (mp[num]) return true;
            mp[k-num] = 1;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
};
