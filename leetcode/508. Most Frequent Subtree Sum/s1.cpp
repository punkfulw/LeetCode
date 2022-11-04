// OJ: https://leetcode.com/problems/most-frequent-subtree-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, int> cnt;
    int highest = 0;

    int dfs(TreeNode* root){
        if (!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int sum = left + right + root->val;
        cnt[sum]++;
        highest = max(highest, cnt[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        dfs(root);
        for (auto &p: cnt)
            if (p.second == highest)
                ans.push_back(p.first);
        return ans;
    }
};
