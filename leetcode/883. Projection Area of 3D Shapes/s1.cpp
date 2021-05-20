// OJ: https://leetcode.com/problems/projection-area-of-3d-shapes/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int x, y;
        
        for (int i = 0; i < n; i++){
            x = 0; y = 0;
            for (int j = 0; j < n; j++){
                x = max(x, grid[i][j]);
                y = max(y, grid[j][i]);
                if (grid[i][j]) ans++;
            }
            ans += x + y;
        }
        return ans;
    }
};
