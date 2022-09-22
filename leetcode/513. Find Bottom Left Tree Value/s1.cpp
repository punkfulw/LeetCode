// OJ: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()){
            int sz = q.size(), set = 0;
            while (sz--){
                auto node = q.front();
                q.pop();
                if (!set){
                    ans = node->val;
                    set = 1;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
