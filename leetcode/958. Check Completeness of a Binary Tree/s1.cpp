// OJ: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Author: github.com/pounkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool pre = true;
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (!cur)
                pre = false;
            else{
                if (!pre)
                    return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
};
