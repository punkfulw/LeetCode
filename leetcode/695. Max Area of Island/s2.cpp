// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, ans = 0;
    int dirs[5] = {1, 0, -1, 0, 1};
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int cur = 1;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            int r = i + dirs[k], c = j + dirs[k + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c])
                cur += dfs(r, c, grid);
        }
        return cur;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, dfs(i, j, grid));  
        
        return ans;
    }
};
