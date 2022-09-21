// OJ: https://leetcode.com/problems/largest-1-bordered-square/
// Author: github.com/punkfulw
// Time: O(MNN)
// Space: O(MN)
class Solution {
public:
    bool check(vector<vector<int>> &prerow, vector<vector<int>> &precol, int i, int j, int len){
        int r1, r2, c1, c2;
        r1 = prerow[i][j + len - 1] - prerow[i][j - 1];
        r2 = prerow[i + len - 1][j + len - 1] - prerow[i + len - 1][j - 1];
        c1 = precol[i + len - 1][j] - precol[i - 1][j];
        c2 = precol[i + len - 1][j + len - 1] - precol[i - 1][j + len - 1];
        return r1 == len && r2 == len && 
               c1 == len && c2 == len;
    }
    
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), len = min(n, m);
        vector<vector<int>> prerow(n + 1, vector<int> (m + 1)), precol(n + 1, vector<int> (m + 1));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                precol[i][j] = precol[i - 1][j] + grid[i - 1][j - 1];
                prerow[i][j] = prerow[i][j - 1] + grid[i - 1][j - 1];
            }
        }
        
        for (; len >= 1; len--)
            for (int i = 0; i < n - len + 1; i++)
                for (int j = 0; j < m - len + 1; j++)
                    if (check(prerow, precol, i + 1, j + 1, len))
                        return len * len;

        return len;
    }
};
