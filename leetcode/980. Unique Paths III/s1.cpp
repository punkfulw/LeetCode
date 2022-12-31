// OJ: https://leetcode.com/problems/unique-paths-iii/
// Author: github.com/punkfulw
// Time: O(3^(MN))
// Space: O(MN) 
class Solution {
public:
    int ans = 0, dirs[5] = {1, 0, -1, 0, 1}, n, m, space = 0;
    vector<vector<int>> grid;
    
    void dfs(int i, int j, int end[]){
        if (i == end[0] && j == end[1]){
            ans += space == 0;
            return;
        }
        int ori = grid[i][j];
        grid[i][j] = -1;
        
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != -1){
                space -= grid[r][c] == 0;
                dfs(r, c, end);
                space += grid[r][c] == 0;
            }
        }
        grid[i][j] = ori;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        this->grid = grid;
        
        int start[2], end[2];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                space += grid[i][j] == 0;
                if (grid[i][j] == 1)
                    start[0] = i, start[1] = j;
                else if (grid[i][j] == 2)
                    end[0] = i, end[1] = j;
            }

        dfs(start[0], start[1], end);
        return ans;
    }
};
