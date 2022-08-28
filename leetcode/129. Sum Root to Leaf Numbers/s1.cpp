// OJ: https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    void sol(TreeNode* root, int &cnt, int &ans){
        cnt = cnt * 10 + root->val;
        if (!root->left && !root->right){
            ans += cnt;
            cnt /= 10;
            return;
        }
        if (root->left)
            sol(root->left, cnt, ans);
        if (root->right)
            sol(root->right, cnt, ans);
        cnt /= 10;
    }
    
    int sumNumbers(TreeNode* root) { 
        int cnt = 0, ans = 0;
        sol(root, cnt, ans);
        return ans;
    }
};
