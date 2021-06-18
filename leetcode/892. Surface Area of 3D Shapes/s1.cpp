// OJ: https://leetcode.com/problems/surface-area-of-3d-shapes/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int cur = grid[i][j];
                if (cur != 0){
                    ans += cnt_surface(cur);
                    if (j + 1 < n)
                        ans -= 2 * min(cur, grid[i][j+1]);
                    if (i + 1 < n)
                        ans -= 2 * min(cur, grid[i+1][j]);
                }
            }
        }
        return ans;
    }
    
    int cnt_surface(int n){
        if (n == 1)
            return 6;
        return (5 * 2) + (4 * (n - 2)); 
    }
};
