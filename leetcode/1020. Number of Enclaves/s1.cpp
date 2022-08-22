// OJ: https://leetcode.com/problems/number-of-enclaves/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, dirs[5] = {1, 0, -1, 0, 1}, ans = 0;
    
    bool dfs(vector<vector<int>>&grid, int i, int j, int &cnt){
        grid[i][j] = 0;
        cnt++;
        bool reach = 0;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            reach = 1;
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c])
                reach |= dfs(grid, r, c, cnt);
        }
        return reach;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    int cnt = 0;
                    bool reach = dfs(grid, i, j, cnt);
                    if (!reach)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};
