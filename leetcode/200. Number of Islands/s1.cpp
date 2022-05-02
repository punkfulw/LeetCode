// OJ: https://leetcode.com/problems/number-of-islands/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, ans = 0;
    int dirs[5] = {1, 0, -1, 0, 1};
    
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k], y = j + dirs[k + 1];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1')
                dfs(x, y, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid);
                }

        return ans;
    }
};
