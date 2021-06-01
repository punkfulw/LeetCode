// OJ: https://leetcode.com/problems/max-area-of-island/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int cur = dfs(i, j, grid);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
            grid[i][j] = -1;
            return 1 + dfs(i-1, j, grid) + dfs(i+1, j, grid) + dfs(i, j-1, grid) + dfs(i, j+1, grid);
        }
        return 0;
    }
};
