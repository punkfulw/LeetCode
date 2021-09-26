// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        bool valid = true;
        getnums(root, nums, valid);
        return valid;
    }
    void getnums(TreeNode* root, vector<int>& nums, bool& valid){
        if (root){
            getnums(root->left, nums, valid);
            if (nums.size()){
                if (nums.back() >= root->val){
                    valid = false;
                    return;
                }
            }
            nums.push_back(root->val);
            getnums(root->right, nums, valid);
        }
        return;
    }
};
