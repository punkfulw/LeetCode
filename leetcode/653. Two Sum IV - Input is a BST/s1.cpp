// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return findsum(root, k, mp);
    }
    bool findsum(TreeNode* root, int k, unordered_map<int, int>& mp){
        if (!root) return false;
        int cur = root->val;
        if (mp[cur]) return true;
        mp[k - cur] = 1;
        return findsum(root->left, k, mp) || findsum(root->right, k, mp);
    }
};
