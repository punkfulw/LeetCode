// OJ: https://leetcode.com/problems/game-of-life/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(NM)
class Solution {
public:
    int n, m;
    void check(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& board)
    {
        int ones = 0;
        for (int i = row - 1; i <= row + 1 ; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if ((i == row && j == col) || i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                ones += board[i][j];
            }
        }
        if (board[row][col] == 1)
        {
            if (ones < 2)
                ans[row][col] = 0;
            else if (ones > 3)
                ans[row][col] = 0;
        }
        else
        {
            ans[row][col] = ones == 3 ? 1 : 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        vector<vector<int>> ans = board;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                check(i, j, ans, board);
        board = ans;
        
    }
};
