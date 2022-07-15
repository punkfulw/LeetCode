// OJ: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int rec[10] = {};
    void dfs(TreeNode* root, int &ans){
        rec[root->val]++;
        if (!root->left && !root->right){
            int odd = 0;
            for (auto i: rec)
                if (i % 2)
                    odd++;
            if (odd <= 1)
                ans++;
        }
        if (root->left)
            dfs(root->left, ans);
        if (root->right)
            dfs(root->right, ans);
        rec[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
