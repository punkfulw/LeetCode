// OJ: https://leetcode.com/problems/even-odd-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()){
            int sz = q.size(), pre = lvl % 2 == 0 ? INT_MIN : INT_MAX;
            while (sz--){
                auto node = q.front();
                q.pop();
                int val = node->val;
                if (lvl % 2 && (val % 2 || val >= pre))
                    return false;
                else if (lvl % 2 == 0 && (val % 2 == 0 || val <= pre)) 
                    return false;
                pre = val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            lvl++;
        }
        return true;
    }
};
