// OJ: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1568.%20Minimum%20Number%20of%20Days%20to%20Disconnect%20Island/README.md
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
public:
    int n, m, cnt = 0, dirs[5] = {1, 0, -1, 0, 1};
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis){
        vis[i][j] = 1;
        
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1)
                dfs(grid, r, c, vis);
        }
    }
    
    bool disCon(vector<vector<int>>& grid){
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    if (++cnt > 1)
                        return true;
                    dfs(grid, i, j, vis);
                }
            }
        return cnt == 0;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        if (disCon(grid))
            return 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1){
                    grid[i][j] = 0;
                    if (disCon(grid))
                        return 1;
                    grid[i][j] = 1;
                }

        
        return 2;
    }
};
