## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    int n, m, ans = 0, dirs[5] = {1, 0, -1, 0, 1};
    
    void dfs(int i, int j, vector<vector<char>> &board){
        board[i][j] = '.';
        for (int d = 0; d < 4; d++){
            int r = i + dirs[d], c = j + dirs[d + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'X')
                dfs(r, c, board);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (board[i][j] == 'X'){
                    dfs(i, j, board);
                    ans++;
                }
            }
        return ans;
    }
};
```
