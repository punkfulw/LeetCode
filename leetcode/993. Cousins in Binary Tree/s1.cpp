// OJ: https://leetcode.com/problems/cousins-in-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            bool findx = false, findy = false;
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                if (cur->left && cur->right)
                    if ((cur->left->val == x && cur->right->val == y) || (cur->left->val == y && cur->right->val == x))
                        return false; 
                if (cur->val == x)
                    findx = true;
                else if (cur->val == y)
                    findy = true;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (findx && findy)
                return true;
        }
        return false;
    }
};
