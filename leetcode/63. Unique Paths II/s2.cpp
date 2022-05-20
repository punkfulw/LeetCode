// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rec[101][101] {};
        int n = grid.size(), m = grid[0].size();
        rec[0][1] = 1;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!grid[i - 1][j - 1])
                    rec[i][j] += rec[i - 1][j] + rec[i][j - 1];
 
        
        return rec[n][m];
    }
};
