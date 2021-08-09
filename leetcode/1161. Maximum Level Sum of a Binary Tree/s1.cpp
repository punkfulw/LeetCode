// OJ: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int mx = INT_MIN;
        int level = 1, ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            int sum = 0;
            
            for (int i = 0; i < n; i++){
                auto r = q.front();
                q.pop();
                sum += r->val;
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            if (sum > mx){
                mx = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
