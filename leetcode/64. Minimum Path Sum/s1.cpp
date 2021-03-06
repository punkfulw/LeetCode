// OJ: https://leetcode.com/problems/minimum-path-sum/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();
        for (int i = 1; i < n; i++)
            dp[i][0] += dp[i-1][0];
        for (int j = 1; j < m; j++)
            dp[0][j] += dp[0][j-1];
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
