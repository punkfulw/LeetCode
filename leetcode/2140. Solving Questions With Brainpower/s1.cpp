// OJ: https://leetcode.com/problems/solving-questions-with-brainpower/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    #define ll long long 
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size(), CD = 0;
        vector<vector<ll>> dp(n, vector<ll> (2, 0));
        dp[n - 1][0] = 0, dp[n - 1][1] = q[n - 1][0];
        
        for (int i = n - 2; i >= 0; i--){
            int CD = i + q[i][1] + 1;
            dp[i][0] = max(dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = CD < n ? q[i][0] + max(dp[CD][1], dp[CD][0]) : q[i][0];
        }

        return max(dp[0][1], dp[0][0]);
    }
};
