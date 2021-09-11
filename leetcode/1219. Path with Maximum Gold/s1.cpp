// OJ: https://leetcode.com/problems/path-with-maximum-gold/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/path-with-maximum-gold/discuss/398228/C%2B%2B-DFS
// Time: O(k * 3 ^ k), where k is the number of cells with gold. We perform the analysis for k cells, and from each cell we can go in three directions.
// Space: O(k) for the recursion.
class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0}; 
    int n, m, ans;
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dig(grid, i, j));
        return ans;
    }
    int dig(vector<vector<int>>& grid, int r, int c){
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] <= 0)
            return 0;
        grid[r][c] = -grid[r][c];
        int next = 0;
        for (int i = 0; i < 4; i++){
            int row = r + dir[i], col = c + dir[i+1];
            next = max(next, dig(grid, row, col));
        }
        grid[r][c] = -grid[r][c];
        return grid[r][c] + next;;
    }
};
