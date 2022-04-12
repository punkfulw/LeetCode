// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/game-of-life/discuss/73230/C%2B%2B-O(1)-space-O(mn)-time
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    int n, m;
    void check(int row, int col, vector<vector<int>>& board)
    {
        int ones = 0;
        for (int i = row - 1; i <= row + 1 ; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if ((i == row && j == col) || i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                ones += board[i][j] & 1;
            }
        }
        if ((board[row][col] & 1 && ones == 2) || ones == 3)
            board[row][col] |= 2;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check(i, j, board);       
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] >>= 1;
    }
};
