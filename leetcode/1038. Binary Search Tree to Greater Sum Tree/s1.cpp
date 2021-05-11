// OJ: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/discuss/288753/100-c%2B%2B-solution
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void cntTree(TreeNode* root, int& sum){
        if (root == NULL)
            return;
        cntTree(root->right, sum);
        sum += root->val;
        root->val = sum;
        cntTree(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        cntTree(root, sum);
        
        return root;
    }
};
