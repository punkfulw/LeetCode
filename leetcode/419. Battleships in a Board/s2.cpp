## Solution 2. findHead

// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    int n, m, ans = 0;
    
    bool checkHead(int i, int j, vector<vector<char>>& board){
        if (i > 0 && board[i - 1][j] == 'X')
            return false;
        if (j > 0 && board[i][j - 1] == 'X')
            return false;
        return true;
    }
    
    int countBattleships(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'X' && checkHead(i, j, board))
                    ans++;

        return ans;
    }
};


