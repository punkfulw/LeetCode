// OJ: https://leetcode.com/problems/merge-intervals/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (auto &p: nums){
            if (ans.empty() || p[0] > ans.back()[1])
                ans.push_back(p);
            else 
                ans.back()[1] = max(ans.back()[1], p[1]);
        }
        return ans;
    }
};
