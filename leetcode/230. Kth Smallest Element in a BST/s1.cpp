// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root || !stk.empty())
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            TreeNode* cur = stk.top();
            stk.pop();
            if (--k == 0)
                return cur->val;
            root = cur->right;
        }
        return 0;
    }
};
