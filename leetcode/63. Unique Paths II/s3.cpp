// OJ: https://leetcode.com/problems/unique-paths-ii/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rec[100] {};
        int n = grid.size(), m = grid[0].size();
        rec[0] = 1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    rec[j] = 0;
                else if (j > 0)
                    rec[j] += rec[j - 1];
        return rec[m - 1];
    }
};
