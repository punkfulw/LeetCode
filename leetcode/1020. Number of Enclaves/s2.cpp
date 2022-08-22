// OJ: https://leetcode.com/problems/number-of-enclaves/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int n, m, dirs[5] = {1, 0, -1, 0, 1}, ans = 0;
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    int cnt = 0, reach = 0;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        cnt++;
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                            reach = 1;
                        for (int d = 0; d < 4; d++){
                            int r = x + dirs[d], c = y + dirs[d + 1];
                            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c]){
                                grid[r][c] = 0;
                                q.push({r, c});
                            }
                        }
                    }
                    if (!reach)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};
