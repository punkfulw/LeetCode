// OJ: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:   
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            double num = 0;
            for (int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                num += cur->val;
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(num/n);
        }
        return ans;
    }
};
