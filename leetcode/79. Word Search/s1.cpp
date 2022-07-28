// OJ: https://leetcode.com/problems/word-search/
// Author: github.com/punkfulw
// Time: O(MN * 4^W)
// Space: O(W)
class Solution {
public:
    int n, m, dirs[5] = {0, 1, 0, -1, 0}, sz;
    bool dfs(int i, int j, int idx, string word, vector<vector<char>>& board){
        if (idx == sz - 1)
            return true;
        char tmp = board[i][j];
        board[i][j] = '0';
        bool ret = 0;
        for (int d = 0; d < 4 && !ret; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == word[idx + 1]){
                ret |= dfs(r, c, idx + 1, word, board);
            }
        }
        board[i][j] = tmp;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), sz = word.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0] && dfs(i, j, 0, word, board))
                    return true;;
        return false;
    }
};
