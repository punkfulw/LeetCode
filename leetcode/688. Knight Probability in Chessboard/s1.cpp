// OJ: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: github.com/punkfulw
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
public:
    int dirs[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1},
                      {-2, -1}, {-1, -2}, {1, -2}, {-2, 1}};
    double dp[26][26][101] = {};
    
    double sol(int n, int k, int row, int col) {
        double in = 0, prob = 0;
        if (k == 0)
            return 1;
        if (dp[row][col][k] != -1)
            return dp[row][col][k];
        
        for (int d = 0; d < 8; d++){
            int r = row + dirs[d][0], c = col + dirs[d][1];
            if (r < 0 || r >= n || c < 0 || c >= n)
                continue;
            prob += sol(n, k - 1, r, c);
        }
        return dp[row][col][k] = prob / 8;
    }
    
    double knightProbability(int n, int k, int row, int col) {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 101; ++k)
                    dp[i][j][k] = -1;
        return sol(n, k, row, col);
    }
};

