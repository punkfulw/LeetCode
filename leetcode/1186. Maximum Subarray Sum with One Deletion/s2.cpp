// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, dp[2][2] = {};
        for (int i = 0; i < n; i++){
            int cur = i % 2 ? 1 : 0;
            int pre = i % 2 ? 0 : 1;
            dp[cur][0] = max(nums[i], dp[pre][0] + nums[i]);
            dp[cur][1] = max(dp[pre][1] + nums[i], dp[pre][0]);
            ans = max(ans, dp[cur][0]);
            if (i > 1)
                ans = max(ans, dp[cur][1]);
        }
        return ans;
    }
};
