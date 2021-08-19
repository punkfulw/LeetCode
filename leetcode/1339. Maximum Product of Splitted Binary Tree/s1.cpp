// OJ: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/496491/C%2B%2B-DFS
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int MOD = 1e9 + 7;
    long total = 0, ans = 0; 
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root);

        return ans % (int)MOD;
    }
    
    int dfs(TreeNode* root){
        if (!root)
            return 0;
        long cur = root->val + dfs(root->left) + dfs(root->right);
        ans = max(ans, (total - cur) * cur);
        return cur;
    }
};
