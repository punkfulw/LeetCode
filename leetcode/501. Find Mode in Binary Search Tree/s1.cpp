// OJ: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> ans;
    int pre = INT_MIN, cnt = 0, mx = 0;
    void sol(TreeNode* root){
        if (!root) 
            return;
        sol(root->left);
        if (root->val == pre)
            cnt++;
        else 
            cnt = 1;
        pre = root->val;
        if (cnt == mx)
            ans.push_back(root->val);
        if (cnt > mx){
            ans = vector<int> {};
            ans.push_back(root->val);
            mx = cnt;
        }
        sol(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        sol(root);
        return ans;
    }
};
