// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int> (2));
        for (int i = 0; i < n; i++){
            dp[i + 1][0] = max(nums[i], dp[i][0] + nums[i]);
            dp[i + 1][1] = max(dp[i][1] + nums[i], dp[i][0]);
            ans = max(ans, dp[i + 1][0]);
            if (i > 1)
                ans = max(ans, dp[i + 1][1]);
        }
        return ans;
    }
};
