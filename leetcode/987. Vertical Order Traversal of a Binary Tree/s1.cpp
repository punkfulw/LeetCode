// OJ: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    map<int, vector<pair<int, int>>> mp;
    
    void sol(TreeNode* root, int row, int col){
        if (!root)
            return;
        mp[col].push_back({row, root->val});
        sol(root->left, row + 1, col - 1);
        sol(root->right, row + 1, col + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        sol(root, 0, 0);    
        vector<vector<int>> ans;
        
        for (auto &p: mp){
            sort(p.second.begin(), p.second.end());
            vector<int> cur;
            for (auto &pr: p.second)
                cur.push_back(pr.second);
            ans.push_back(cur);
        } 
        
        return ans;
    }
};
