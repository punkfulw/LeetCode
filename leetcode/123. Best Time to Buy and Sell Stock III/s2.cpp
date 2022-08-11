// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), dp[2][4] = {{-100001, 0, -100001, 0}}, ans = 0, nxt = 1, cur = 0;  
        
        for (int i = 0; i < n; i++){
            dp[nxt][0] = max(dp[cur][0], - nums[i]);
            dp[nxt][1] = max(dp[cur][1], nums[i] + dp[cur][0]);
            dp[nxt][2] = max(dp[cur][2], dp[cur][1] - nums[i]);
            dp[nxt][3] = max(dp[cur][3], nums[i] + dp[cur][2]);
            swap(nxt, cur);
        }
        return max(dp[cur][1], dp[cur][3]);
    }
};
