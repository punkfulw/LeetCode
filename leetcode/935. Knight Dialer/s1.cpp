// OJ: https://leetcode.com/problems/knight-dialer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int dirs[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, 
                      {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    long n = 4, m = 3, MOD = 1e9 + 7, ans = 0;
    long dp[4][3][5005] = {};
    
    int dfs(int i, int j, int N){
        if ((i == n - 1 && j == m - 1) || (i == n - 1 && j == 0))
            return 0;
        
        if (dp[i][j][N] != -1)
            return dp[i][j][N];
        if (N == 0)
            return 1;
        
        long ret = 0;
        for (auto dir: dirs){
            int r = i + dir[0], c = j + dir[1];
            if (r >= 0 && r < n && c >= 0 && c < m)
                ret = (ret + dfs(r, c, N - 1)) % MOD;
        }
        return dp[i][j][N] = ret;
    }
    
    int knightDialer(int N) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 5005; k++)
                    dp[i][j][k] = -1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = (ans + dfs(i, j,  N - 1)) % MOD;

        return ans;
    }
};
