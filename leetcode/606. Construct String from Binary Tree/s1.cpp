// OJ: https://leetcode.com/problems/construct-string-from-binary-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    string ans;
    
    void sol(TreeNode* root){
        ans += to_string(root->val);
        if (root->left){
            ans += "(";
            sol(root->left);
            ans += ")";
        }
        if (root->right){
            if (!root->left)
                ans += "()";
            ans += "(";
            sol(root->right);
            ans += ")";
        }
    }
    
    string tree2str(TreeNode* root) {
        sol(root);
        return ans;
    }
};
