// OJ: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(Q)
class Solution {
public: 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 1, ans = -1;
        if (grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        
        while (!q.empty() && ans == -1){
            int m = q.size();
            for (int i = 0; i < m; i++){
                auto [x, y] = q.front(); q.pop();
                if (x == n - 1 && y == n - 1){
                    ans = cnt;
                    break;
                }  
                for (int i = x - 1; i <= x + 1; i++)
                    for (int j = y - 1; j <= y + 1; j++)
                        if (i >= 0 && i < n && j >= 0 && j < n && !grid[i][j]){
                            grid[i][j] = 1;
                            q.push({i, j});
                        } 
            }
            cnt++;
        }
        return ans;
    }
};
