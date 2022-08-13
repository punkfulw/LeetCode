// OJ: https://leetcode.com/problems/cherry-pickup-ii/
// Author: github.com/punkfulw
// Time: O(N * M^2)
// Space: O(N * M^2)
class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int dfs(vector<vector<int>> &grid, int i, int c1, int c2){
        if (i == n)
            return 0;
        if (dp[i][c1][c2] != -1)
            return dp[i][c1][c2];
        int cnt = 0;
        for (int nxt_c1 = max(0, c1 - 1); nxt_c1 <= min(m - 1, c1 + 1); nxt_c1++)
            for (int nxt_c2 = max(0, c2 - 1); nxt_c2 <= min(m - 1, c2 + 1); nxt_c2++)
                cnt = max(cnt, dfs(grid, i + 1, nxt_c1, nxt_c2));

        cnt += c1 == c2 ? grid[i][c1] : grid[i][c1] + grid[i][c2];
        return dp[i][c1][c2] = cnt;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int> (m, -1)));
        return dfs(grid, 0, 0, m - 1);
    }
};



