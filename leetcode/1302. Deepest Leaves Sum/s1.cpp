// OJ: https://leetcode.com/problems/deepest-leaves-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int deepest(TreeNode* p){
        if (p == nullptr)
            return 0;
        else{
            int l = deepest(p -> left);
            int r = deepest(p -> right);
            return max(l, r) + 1;
        }
    };
    int deepestLeavesSum(TreeNode* root) {
        int maxD = deepest(root);
        int ans = leavesSum(root, maxD);
        
        return ans;
    }

    int leavesSum(TreeNode* root, int maxD){
        if (root == nullptr)
            return 0;
        if (maxD == 1)
            return root -> val;
        return leavesSum(root -> left, maxD - 1) + leavesSum(root -> right, maxD - 1);
    }
};
