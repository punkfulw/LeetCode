// OJ: https://leetcode.com/problems/maximum-binary-tree/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int pos = start;
        for (int i = start; i <= end; i++)
            if (nums[i] > nums[pos])
                pos = i;  
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = solve(nums, start, pos - 1);
        root->right = solve(nums, pos + 1, end);
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
