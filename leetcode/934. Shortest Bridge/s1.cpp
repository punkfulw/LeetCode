// OJ: https://leetcode.com/problems/shortest-bridge/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    #define pii pair<int, int>
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), step = 0, dirs[5] = {1, 0, -1, 0, 1}, done = 0;
        vector<vector<int>> vis(n, vector<int> (n));
        queue<pii> q1, q;
        for (int i = 0; i < n && !done; i++)
            for (int j = 0; j < n && !done; j++)
                if (grid[i][j] == 1){
                    q1.push({i, j});
                    vis[i][j] = 1;
                    while (!q1.empty()){
                        int sz = q1.size();
                        while (sz--){
                            auto [x, y] = q1.front();
                            q1.pop();
                            q.push({x, y});
                            for (int d = 0; d < 4; d++){
                                int r = x + dirs[d], c = y + dirs[d + 1];
                                if (r >= 0 && r < n && c >= 0 && c < n 
                                    && grid[r][c] == 1 && !vis[r][c]){
                                    q1.push({r, c});
                                    vis[r][c] = 1;
                                }
                            }
                        }
                    }
                    done = 1;
                }

        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++){
                    int r = x + dirs[d], c = y + dirs[d + 1];
                    if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c]){
                        if (grid[r][c] == 1)
                            return step;
                        q.push({r, c});
                        vis[r][c] = 1;
                    }
                }
            }
            step++;
        }
        return step;
    }
};


