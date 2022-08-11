// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), dp[100001][4] = {{-100001, 0, -100001, 0}}, ans = 0, nxt = 1, cur = 0;  
        
        for (int i = 0; i < n; i++){
            dp[i + 1][0] = max(dp[i][0], - nums[i]);
            dp[i + 1][1] = max(dp[i][1], nums[i] + dp[i][0]);
            dp[i + 1][2] = max(dp[i][2], dp[i][1] - nums[i]);
            dp[i + 1][3] = max(dp[i][3], nums[i] + dp[i][2]);
        }
        return max(dp[n][1], dp[n][3]);
    }
};
