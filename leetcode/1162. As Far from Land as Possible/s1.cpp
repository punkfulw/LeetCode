// OJ: https://leetcode.com/problems/as-far-from-land-as-possible/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), dirs[5] = {1, 0, -1, 0, 1};
        vector<vector<int>> vis(n, vector<int> (n));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
        
        int dis = 1, ans = -1;
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++){
                    int r = i + dirs[d], c = j + dirs[d + 1];
                    if (r >= 0 && r < n && c >= 0 && c < n && !vis[r][c] && grid[r][c] == 0){
                        vis[r][c] = dis;
                        ans = max(ans, dis);
                        q.push({r, c});
                    }
                }
            }
            dis++;
        }
        return ans;
    }
};
