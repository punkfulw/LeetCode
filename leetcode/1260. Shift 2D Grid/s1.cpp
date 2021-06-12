// OJ: https://leetcode.com/problems/shift-2d-grid/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k % (n * m);
        vector<vector<int>> ans (n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int newRow =(i + (j+k) / m) % n;
                int newCol = (j+k) % m;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;
    }
};
