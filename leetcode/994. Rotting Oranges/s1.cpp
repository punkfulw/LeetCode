// OJ: https://leetcode.com/problems/rotting-oranges/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int good = 0, n = grid.size(), m = grid[0].size(), mins = 0;
        queue<pair<int, int>> q;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) continue;
                else if (grid[i][j] == 2) 
                    q.push({i, j});
                else good++;
            }
        }
        if (good == 0) return 0;
        while (!q.empty()){
            int k = q.size();
            for (int i = 0; i < k; i++){
                auto p = q.front(); q.pop();
                for (int i = 0; i < 4; i++){
                    int r = p.first + dir[i][0], c = p.second + dir[i][1];
                    if (r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1){
                        q.push({r, c});
                        grid[r][c] = 2;
                        good--;
                    }
                }
            }
            mins++;
            if (good == 0) return mins;
        }
        return good == 0 ? mins : -1;
    }
};
