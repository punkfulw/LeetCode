// OJ: https://leetcode.com/problems/maximal-square/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:  
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dp[i + 1][j + 1] = mat[i][j] == '1' ? 1 : 0;
                if (mat[i][j] == '1')
                    dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i][j], dp[i + 1][j]}) + 1;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};
