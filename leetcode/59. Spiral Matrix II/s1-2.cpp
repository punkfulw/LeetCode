// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x = 0, y = 0, dir = 0, cnt = 1;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int board[4] = {n - 1, n - 1, 0, 1};

        while (cnt <= n * n)
        {
            ans[x][y] = cnt++;
            int newX = x + dirs[dir][0], newY = y + dirs[dir][1];
            if ((dir % 2 && (newX < board[3] || newX > board[1]))|| (dir % 2 == 0 && (newY < board[2] || newY > board[0])))
            {
                if (dir < 2)
                    board[dir]--;
                else
                    board[dir]++;
                dir = (dir + 1) % 4;
            }
            x += dirs[dir][0];
            y += dirs[dir][1];
        }
        return ans;
    }
};
