// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/punkfulw
// Time: O(3^(MN))
// Space: O(MN) 
class Solution {
public:
    int n, m, dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, ans = 0, end_x, end_y, ttl = 1;
    
    void dfs(int x, int y, int cnt, vector<vector<int>>& grid){
        if (grid[x][y] == -1)
            return;
        if (grid[x][y] == 2){
            ans += cnt == ttl;
            return;
        }
        
        grid[x][y] = 1;
        for (int d = 0; d < 4; d++){
            int r = x + dirs[d][0], c = y + dirs[d][1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != 1)
                dfs(r, c, cnt + 1, grid);
        }
        grid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int x, y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1)
                    x = i, y = j;
                else if (grid[i][j] == 2)
                    end_x = i, end_y = j;
                else if (grid[i][j] == 0)
                    ttl++;
            }
        }
        dfs(x, y, 0, grid);
        return ans;
    }
};
