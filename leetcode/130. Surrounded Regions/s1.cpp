// OJ: https://leetcode.com/problems/surrounded-regions/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m;
    int dirs[5] = {0, 1, 0, -1, 0};
    
    void dfs(int i, int j, vector<vector<char>>& board){
        board[i][j] = '#';
        
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O')
                dfs(r, c, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++){
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }
        
        for (int j = 0; j < m; j++){
            if (board[0][j] == 'O')
                dfs(0, j, board);
            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        
        return;
    }
};
