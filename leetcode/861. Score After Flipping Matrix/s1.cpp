// OJ: https://leetcode.com/problems/score-after-flipping-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            if (grid[i][0] == 0)
                for (int j = 0; j < m; j++)
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
        
        for (int j = 1; j < m; j++){
            int cnt1 = 0;
            for (int i = 0; i < n; i++)
                if (grid[i][j] == 1)
                    cnt1++;
            if (cnt1 <= n/2)
                for (int i = 0; i < n; i++)
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0; 
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = m-1; j >= 0; j--)
                if (grid[i][j])
                    ans += grid[i][j] * pow(2, m-j-1);
        return ans;
    }
};
