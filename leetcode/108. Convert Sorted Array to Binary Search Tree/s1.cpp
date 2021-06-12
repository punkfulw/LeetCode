// OJ: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        return helper(nums, 0, nums.size()-1, root);
    }
    TreeNode* helper(vector<int>& nums, int start, int end, TreeNode* root){
        if (start <= end){
            int m = (start + end) / 2;
            TreeNode* cur = new TreeNode(nums[m]);
            cur->left = helper(nums, start, m-1, root);
            cur->right = helper(nums, m+1, end, root);
            return cur;
        }
        return NULL;
    }
};
