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
        vector<int> f = {};
        queue<vector<int>> q;
        q.push(f);
        
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            int sum = accumulate(cur.begin(), cur.end(), 0);
            if (sum == target)
                ans.push_back(cur);
            else if (sum < target){
                for (int i : can){
                    if (cur.empty() || i >= cur.back()){
                        cur.push_back(i);
                        q.push(cur);
                        cur.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};
