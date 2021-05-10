// OJ: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/477048/JavaC%2B%2BPython-1-Line-Recursive-Solution
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, p)
               + sumEvenGrandparent(root->right, root->val, p)
               + (gp % 2 ? 0 : root->val)  : 0;
    }
};
