// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int ans = 0, n;
    unordered_map<int, int> dp;
    
    int dfs(int i, int tar, vector<int>& nums){
        if (tar < 0)
            return 0;
        if (0 == tar)
            return 1;
        if (dp.find(tar) != dp.end())
            return dp[tar];
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += dfs(j, tar - nums[j], nums);
        return dp[tar] = cnt; 
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        for (int i = 0; i < n; i++)
            ans += dfs(i, target - nums[i], nums);
        return ans;
    }
};
