// OJ: https://leetcode.com/problems/range-sum-of-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans {};
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root != nullptr){
            if (root -> val >= low && root -> val <= high)
                ans += root -> val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        }
        return ans;
    }
};
