// OJ: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(logN)
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        int lvl = 1;
        while (!q.empty()){
            int n = q.size();
            while (n--){
                auto node = q.front();
                q.pop();
                if (node->left == NULL && node->right == NULL)
                    return lvl;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                q.push(node->right);
            }
            lvl++;
        }
        return -1;
    }
};
