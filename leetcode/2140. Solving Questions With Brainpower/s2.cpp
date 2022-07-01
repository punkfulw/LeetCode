// OJ: https://leetcode.com/problems/solving-questions-with-brainpower/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    #define ll long long 
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size(), CD = 0;
        vector<ll> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--){
            int CD = min(n, i + q[i][1] + 1);
            dp[i] = max(dp[i + 1], q[i][0] + dp[CD]);
        }

        return dp[0];
    }
};
