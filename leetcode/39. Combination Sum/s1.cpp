// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        if (*min_element(can.begin(), can.end()) > target)
            return ans;
        vector<int> cur;
        dfs(can, cur, target, ans);
        return ans;
    }
    void dfs(vector<int>& can, vector<int> cur, int target, vector<vector<int>>& ans){
        if (target < 0)
            return;
        else if (target == 0){
            ans.push_back(cur);
            return;
        }
        for (int i: can){
            if (cur.empty() || i >= cur.back()){
                cur.push_back(i);
                dfs(can, cur, target-i, ans);
                cur.pop_back();
            }
        }
        return;
    }
};
