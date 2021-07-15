// OJ: https://leetcode.com/problems/valid-sudoku/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.' && (!check1(board, i, j) || !check2(board, i, j)))
                    return false;
            }
        }
        return true;
    }
    bool check1(vector<vector<char>>& board, int row, int col){
        int r = row / 3 * 3, c = col / 3 * 3;
        int cnt = 0;
        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++)
                if (board[i][j] == board[row][col])
                    cnt++;
        return cnt == 1 ? true : false;

    }
    bool check2(vector<vector<char>>& board, int row, int col){
        int cntr = 0, cntc = 0;
        for (int i = 0; i < 9; i++){
            if (board[row][i] == board[row][col])
                cntc++;
            if (board[i][col] == board[row][col])
                cntr++;
        }
        if (cntc == 1 && cntr == 1)
            return true;
        return false;
    }
};
