// OJ: https://leetcode.com/problems/integer-break/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sol(int n, vector<int> &dp){
        if (n == 0) return 0;
        if (n <= 2) return 1;
        if (dp[n])  return dp[n];
        int mx = 0;
        for (int i = 1; i <= n / 2; i++){
            mx = max(mx, i * (n - i));
            mx = max(mx, sol(i, dp) * sol(n - i, dp));
            mx = max(mx, sol(i, dp) * (n - i));
            mx = max(mx, i * sol(n - i, dp));
        }
        return dp[n] = mx;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        return sol(n, dp);
    }
};
