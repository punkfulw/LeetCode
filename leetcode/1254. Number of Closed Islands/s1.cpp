// OJ: https://leetcode.com/problems/number-of-closed-islands/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m , ans = 0;
    int dirs[5] = {1, 0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<int>>& grid, bool &isIsland)
    {
        if (i == n - 1 || i == 0 || j == 0 || j == m - 1)
            isIsland = false;
  
        grid[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0)
                dfs(x, y, grid, isIsland);
        }
        return;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                {
                    bool isIsland = true;
                    dfs(i, j, grid, isIsland);
                    ans += isIsland;
                }
        
        return ans;
    }
};
