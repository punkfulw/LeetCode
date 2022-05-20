// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int n, m, ans = 0;
    int rec[100][100] {};
    
    int dfs(int r, int c, vector<vector<int>>& grid){
        if (grid[r][c])
            return 0;
        
        if (rec[r][c] || (r == n - 1 && c == m - 1)){
            ans += rec[r][c];
            return rec[r][c];
        }
        if (r + 1 < n)
            rec[r][c] += dfs(r + 1, c, grid);
        if (c + 1 < m)
            rec[r][c] += dfs(r, c + 1, grid);
        return rec[r][c];           
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        rec[n - 1][m - 1] = 1;
        dfs(0, 0, grid);
        
        
        return ans;
    }
};
